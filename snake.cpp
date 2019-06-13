/*
snake version 1.0.3

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

enum ObjectType{SOLID, FOOD};   //for collision
enum Direction{LEFT, RIGHT, TOP, BOTTOM};   //for moving

class Food;
class Score;
class Snake;
class GameMain;
class Controller;
//TODO implement it!
class CollisionSystem;  //to manage collision objects

class Object{
public:
    ObjectType getType(){
        return type;
    };

    Position getPos(){
        return pos;
    }

    //befor collision, collision, after collision
    virtual void precollision(Object& obj) = 0;
    virtual void collision(Object& obj) = 0;
    virtual void aftercollision() = 0;
protected:
    Position pos;
    ObjectType type;
};

//class Food
class Food:public Object{
public:
    Food(){
        type = ObjectType::FOOD;
        changePos();
    }

    void draw(){
        attron(COLOR_PAIR(2));
        mvaddch(pos.second, pos.first, FOOD);
        attroff(COLOR_PAIR(2));
    }
    
    void changePos(){
        srand(time(nullptr));
        int x = rand()%(COLS-1-1)+1;
        int y = rand()%(LINES-1-1)+1;
        while(!mvinch(y, x)){
            int x = rand()%(COLS-1-1)+1;
            int y = rand()%(LINES-1-1)+1;
        }
        pos = make_pair(x, y);
    }

    void collision(Object& o){}
    void precollision(Object& o){}
    void aftercollision(){
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

    void draw(){
        drawHead();
        drawBody();
    }

    vector<Position> getBody(){
        return body;
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

    void precollision(Object& obj){}

    void collision(Object& obj){
        collisionBorder();
        if(obj.getType() == FOOD){
            Position head = body[0];
            Position foodPos = obj.getPos();
            if(head.first == foodPos.first && head.second == foodPos.second){
                obj.aftercollision();
                Position tail = body[body.size()-1];
                addBody(tail);
                score->increase(1);
            }
        }
    }

    void aftercollision(){}
private:
    static const char SNAKE_BODY = 'S';
    vector<Position> body;
    Direction direction;
    Score* score;
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
    GameMain(){
        init_config();
        init_color();
        snake.init(&score);
    }

    void init_color(){
        init_pair(1, COLOR_GREEN, COLOR_BLACK);  //text color, score color
        init_pair(2, COLOR_BLUE, COLOR_BLACK);   //food color
        init_pair(3, COLOR_YELLOW, COLOR_BLACK); //snake color
        init_pair(4, COLOR_RED, COLOR_BLACK);    //game over text
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
    }


    void drawGameBody(){
        clear();
        box(stdscr, 0, 0);
        score.draw();
        food.draw();
        snake.draw();
        controller.control(snake);
        snake.collision(food);
        snake.step();
        #ifdef DEBUG_SNAKE
        mvprintw(LINES-1, 0, "count:%d", countnum++);
        #endif
        refresh();
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
    Snake snake;
    Food food;
    Score score;
    Controller controller;
};


//main function
int main(){
    GameMain Main;
    Main.run();
    return 0;
}