/*
snake version 1.1.0

used ncurses library.
this game only avaliable at UNIX, LINUX, MacOSX platform.
if you want to play this game please input below line in terminal:

g++ snake.cpp -o snake -lncurses -std=c++11

then open the `snake` to play!

* log
* version 1.0.1
    refactoryed code, from Process-Oriented to Object-Oriented
* version 1.0.3
    refactoryed code, add snake head bold. Fixed bug of turning back.
* version 1.1.0
    added black hole.
*/
#include <ncurses.h>
#include <unistd.h>
#include <random>
#include <ctime>
#include <vector>
#include <utility>
using namespace std;
using Position = pair<int,int>; //first is x, second is y

#ifdef DEBUG_SNAKE
int countnum = 0;
#endif

//a global variable, because this is a single file.
bool isgameover = false;

enum ObjectType{SOLID,
                SIMPLE_FOOD, FUNCTIONAL_FOOD};   //for collision
enum Direction{LEFT, RIGHT, TOP, BOTTOM};   //for moving

class Food;
class Score;
class Snake;
class GameMain;
class Controller;

//Random use to generate random number
class Random{
public:
    static int getInt(){
        checkInit();
        return rand();
    }
    static int getRange(int max, int min){
        checkInit();
        int mod = max-min-1;
        if(mod == 0)
            mod = 1;
        return rand()%mod+min;
    }
private:
    static void checkInit(){
        if(!isinit){
            srand(time(nullptr));
            isinit = true;
        }
    }
    static bool isinit;
};

bool Random::isinit = false;

class Object{
public:
    ObjectType getType(){
        return type;
    };

    virtual Position getPos(){
        return pos;
    }

    virtual void setPos(Position newpos){
        pos = newpos;
    }

    //befor collision, collision, after collision
    virtual void precollision(Object& obj) = 0;
    virtual void collision(Object& obj) = 0;
    virtual void aftercollision() = 0;
    //draw
    virtual void draw() = 0;
protected:
    Position pos;
    ObjectType type;
};

class CollisionSystem{
public:
    CollisionSystem(){}
    void collision(Object& obj1, Object& obj2){
        if(obj1.getPos() == obj2.getPos()){
            obj1.precollision(obj2);
            obj2.precollision(obj1);
            obj1.collision(obj2);
            obj2.collision(obj1);
            obj1.aftercollision();
            obj2.aftercollision();
        }
    }
private:
    //TODO implement vector<Object> ???
};

//class Obstical
class BlackHole : public Object{
public:
    static char BLACK_HOLE;

    BlackHole(int uc, Position pos, BlackHole* another){
        isshow = false;
        this->type = SOLID;
        this->usecount = uc;
        this->pos = pos;
        this->another = another;
        iscol = false;
        assert(pos != another->getPos());
        assert(usecount>0);
    }

    BlackHole(int uc, BlackHole* another){
        isshow = false;
        this->type = SOLID;
        this->usecount = uc;
        iscol = false;
        pos = make_pair(Random::getRange(COLS, 1), Random::getRange(LINES, 1));
        this->another = another;
        if(another != nullptr)
            assert(pos != another->getPos());
    }

    void show(){
        isshow = true;
    }

    void hide(){
        isshow = false;
    }

    void link(BlackHole* an){
        another = an;
    }

    int getusecount(){
        return usecount;
    }

    void decreaseusecount(){
        usecount--;
    }

    //collision
    void precollision(Object& obj) override{}
    void collision(Object& obj) override{
        if(iscol || !isshow)
            return ;
        Position objpos = obj.getPos();
        if(objpos == pos){
            obj.setPos(another->getPos());
            another->decreaseusecount();
            another->post();
        }
    }

    void aftercollision() override{
        if(isshow && !iscol){
            iscol = true;
            decreaseusecount();
        }
    }

    void draw() override{
        if(isshow && usecount > 0){
            attron(COLOR_PAIR(5)|A_BOLD);
            mvaddch(pos.second, pos.first, BLACK_HOLE);
            attroff(COLOR_PAIR(5)|A_BOLD);
        }
    }

    void update(){
        if(usecount <= 0)
            isshow = false;
        iscol = false;
    }

private:
    int usecount;
    BlackHole* another;
    bool isshow;
    bool iscol;
    void post(){
        iscol = true;
    }
};

char BlackHole::BLACK_HOLE = 'O';

//the group of black hole(bind 2 black holes)
/*
Should I declare a virtual class Group, and inherit it?It may simplify the collision.
*/
class BHGroup{
public:
    BHGroup(BlackHole nbh1, BlackHole nbh2):bh1(nbh1), bh2(nbh2){}
    BHGroup(int count):bh1(count, nullptr), bh2(count, nullptr){
        bh1.link(&bh2);
        bh2.link(&bh1);
    }

    void chanegPos(){
        bh1.setPos(make_pair(Random::getRange(COLS,1), Random::getRange(LINES, 1)));
        bh2.setPos(make_pair(Random::getRange(COLS,1), Random::getRange(LINES, 1)));
    }

    void show(){
        bh1.show();
        bh2.show();
    }

    void hide(){
        bh1.hide();
        bh2.hide();
    }

    void draw(){
        bh1.draw();
        bh2.draw();
    }

    BlackHole& getBlackHole1(){
        return bh1;
    }

    BlackHole& getBlackHole2(){
        return bh2;
    }

    void update(){
        bh1.update();
        bh2.update();
    }

private:
    BlackHole bh1;
    BlackHole bh2;
};

//class Food
class Food:public Object{
public:
    Food(){
        type = ObjectType::SIMPLE_FOOD;
        changePos();
    }

    void draw() override{
        attron(COLOR_PAIR(2));
        mvaddch(pos.second, pos.first, FOOD);
        attroff(COLOR_PAIR(2));
    }
    
    void changePos(){
        int x = Random::getRange(COLS, 1);
        int y = Random::getRange(LINES, 1);
        while(!mvinch(y, x)){
            int x = Random::getRange(COLS, 1);
            int y = Random::getRange(LINES, 1);
        }
        pos = make_pair(x, y);
    }

    void collision(Object& o) override{}
    void precollision(Object& o) override{}
    void aftercollision() override{
        changePos();
    }
private:
    static const char FOOD = 'D';
};

//class Score
class Score{
public:
    Score(){
        score = 0;
    }

    int getScore(){
        return score;
    }

    void increase(int num){
        score+=num;
    }

    void decrease(int num){
        score -= num;
    }

    void draw(){
        attron(COLOR_PAIR(1));
        mvprintw(0, 0, "score: %d", score);
        attroff(COLOR_PAIR(1));
    }
private:
    int score;
};

//class Snake
class Snake:public Object{
public:
    Snake(){
        direction = LEFT;
        type = SOLID;
    }

    void init(Score* s){
        addBody(make_pair(COLS/2, LINES/2));
        addBody(make_pair(COLS/2+1, LINES/2));
        pos = body[0];
        score = s;
    }

    int size(){
        return body.size();
    }

    void addBody(Position node){
        body.push_back(node);
    }

    void drawHead(){
        //init_color(COLOR_YELLOW, 700, 700, 0);
        attron(COLOR_PAIR(3)|A_BOLD);
        mvaddch(body[0].second, body[0].first, SNAKE_BODY);
        attroff(COLOR_PAIR(3)|A_BOLD);
        //init_color(COLOR_YELLOW, 1000, 1000, 0);
    }

    void drawBody(){
        attron(COLOR_PAIR(3));
        for(int i=1;i<body.size();i++){
            #ifdef DEBUG_SNAKE
            mvprintw(i, 0, "snake[%d]: x->%d, y->%d", i, body[i].first, body[i].second);
            #endif
            mvaddch(body[i].second, body[i].first, SNAKE_BODY);
        }
        attroff(COLOR_PAIR(3));
    }

    void draw() override{
        drawHead();
        drawBody();
    }

    vector<Position> getBody(){
        return body;
    }

    Position getPos() override{
        return body[0];
    }

    void setPos(Position newpos) override{
        body[0] = newpos;
    }

    void step(){
        body.pop_back();
        Position head = body[0];
        if(direction == LEFT)
            head.first--;
        else if(direction == RIGHT)
            head.first++;
        else if(direction == TOP)
            head.second--;
        else
            head.second++;
        body.insert(body.begin(), head);
    }

    Direction getDirection(){
        return direction;
    }

    void setDirection(Direction dir){
        direction = dir;
    }

    Position& operator[](int idx){
        return body[idx];
    }

    void collisionBorder(){
        Position head = body[0];
        for(int i=1;i<body.size();i++)
            if(head.first == body[i].first && head.second == body[i].second){ 
                isgameover = true;
                return ;
            }
        if(head.first == 0 || head.first == COLS-1 || head.second == 0 || head.second == LINES-1){
            isgameover = true;
            return ;
        }
    }

    void precollision(Object& obj) override{}

    void collision(Object& obj) override{
        if(obj.getType() == SIMPLE_FOOD){
            Position head = body[0];
            Position foodPos = obj.getPos();
            Position tail = body[body.size()-1];
            addBody(tail);
            score->increase(1);
        }
    }

    void aftercollision() override{}
private:
    static const char SNAKE_BODY = 'S';
    vector<Position> body;
    Direction direction;
    Score* score;
};

//class Controller
class Controller{
public:
    Controller(){}

    void control(Snake& snake){
        Direction direction = snake.getDirection();
        switch(getch()){
            case 'a':
                if(snake[0].first-1 != snake[1].first)
                    direction = LEFT;
                break;
            case 'w':
                if(snake[0].second-1 != snake[1].second)
                    direction = TOP;
                break;
            case 'd':
                if(snake[0].first+1 != snake[1].first)
                    direction = RIGHT;
                break;
            case 's':
                if(snake[0].second+1 != snake[1].second)
                    direction = BOTTOM;
                break;
        }
        snake.setDirection(direction);
    }
private:
};

class GameMain{
public:
    GameMain():bhgroup(4){
        init_config();
        init_color();
        timecount = 0;
        snake.init(&score);
        food.changePos();
        bhgroup.chanegPos();
        bhgroup.hide();
    }

    void init_color(){
        init_pair(1, COLOR_GREEN, COLOR_BLACK);     //text color, score color
        init_pair(2, COLOR_BLUE, COLOR_BLACK);      //food color
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);    //snake color
        init_pair(4, COLOR_RED, COLOR_BLACK);       //game over text
        init_pair(5, COLOR_MAGENTA, COLOR_WHITE);   //black hole
    }

    void init_config(){
        isgameover = false;
        initscr();
        if(has_colors() == FALSE){
            endwin();
            isgameover = true;
        }
        start_color();
        curs_set(0);
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        //srand(time(nullptr));
    }

    void drawGameBody(){
        clear();
        drawItems();
        controller.control(snake);
        collisionTest();
        updates();
        #ifdef DEBUG_SNAKE
        mvprintw(LINES-1, 0, "count:%d", countnum++);
        #endif
        refresh();
    }

    void drawItems(){
        box(stdscr, 0, 0);
        score.draw();
        food.draw();
        snake.draw();
        bhgroup.draw();
    }

    void collisionTest(){
        colsystem.collision(snake, food);
        colsystem.collision(snake, bhgroup.getBlackHole1());
        colsystem.collision(snake, bhgroup.getBlackHole2());
        snake.collisionBorder();
    }

    void updates(){
        snake.step();
        bhgroup.update();
        //TODO may have bugs
        if(timecount >= 500)
            bhgroup.show();
    }

    void drawWelcome(){
        clear();
        box(stdscr, 0, 0);
        attron(A_BOLD);
        mvprintw(LINES/2-1, COLS/2-5, "snake game");
        attroff(A_BOLD);
        attron(COLOR_PAIR(1)|A_UNDERLINE);
        mvprintw(LINES/2, COLS/2-11, "press any key to start");
        attroff(COLOR_PAIR(1)|A_UNDERLINE);
        refresh();
        getch();
    }

    void drawGameOver(){
        clear();
        cbreak();
        box(stdscr, 0, 0);
        attron(COLOR_PAIR(4)|A_BOLD);
        mvprintw(LINES/2-1, COLS/2-5, "game over");
        attroff(COLOR_PAIR(4)|A_BOLD);
        attron(COLOR_PAIR(1)|A_UNDERLINE);
        mvprintw(LINES/2, COLS/2-8, "your score is:%d", score);
        attroff(COLOR_PAIR(1)|A_UNDERLINE);
        mvprintw(LINES/2+1, COLS/2-7, "press q to exit");
        refresh();
        while(getch() != 'q');
    }

    void gameloop(){
        halfdelay(DELAY_TIME);
        while(!isgameover){
            drawGameBody();
            timecount++;
        }
    }

    void run(){
        drawWelcome();
        gameloop();
        drawGameOver();
    }

    ~GameMain(){
        endwin();
    }
private:
    static const int DELAY_TIME = 5;
    long long timecount;
    Snake snake;
    Food food;
    Score score;
    BHGroup bhgroup;
    Controller controller;
    CollisionSystem colsystem;
};

//main function
int main(){
    GameMain Main;
    Main.run();
    return 0;
}