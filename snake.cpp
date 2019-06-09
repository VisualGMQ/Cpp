/*
snake version 1.0.0

used ncurses library.
this game only avaliable at UNIX, LINUX, MacOSX platform.
if you want to play this game please input below line in terminal:

g++ snake.cpp -o snake -lncurses -std=c++11

then open the `snake` to play!
*/
#include <ncurses.h>
#include <unistd.h>
#include <random>
#include <ctime>
#include <vector>
#include <utility>
using namespace std;

#ifdef DEBUG_SNAKE
int countnum = 0;
#endif

enum Direction{LEFT, RIGHT, TOP, BOTTOM};

//class Snake
class Snake{
public:
    Snake(){
        direction = LEFT;
    }

    void init(){
        addBody(make_pair(COLS/2, LINES/2));
    }

    int size(){
        return body.size();
    }

    void addBody(pair<int,int> node){
        body.push_back(node);
    }

    void draw(){
        attron(COLOR_PAIR(3)|A_BOLD);
        for(int i=0;i<body.size();i++){
            #ifdef DEBUG_SNAKE
            mvprintw(i, 0, "snake[%d]: x->%d, y->%d", i, body[i].first, body[i].second);
            #endif
            mvaddch(body[i].second, body[i].first, SNAKE_BODY);
        }
        attroff(COLOR_PAIR(3)|A_BOLD);
    }

    vector<pair<int, int>> getBody(){
        return body;
    }

    void step(){
        body.pop_back();
        pair<int, int> head = body[0];
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

    pair<int, int>& operator[](int idx){
        return body[idx];
    }
private:
    static const char SNAKE_BODY = 'S';
    vector<pair<int, int>> body;
    Direction direction;
};

//class Food
class Food{
public:
    Food(){
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

    pair<int, int> getPos(){
        return pos;
    }
private:
    static const char FOOD = 'D';
    pair<int, int> pos;
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

//class Controller
class Controller{
public:
    Controller(){}

    void control(Snake& snake){
        Direction direction = snake.getDirection();
        switch(getch()){
            case 'a':
                direction = LEFT;
                break;
            case 'w':
                direction = TOP;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 's':
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
        snake.init();
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

    void collisionTest(){
        pair<int, int> head = snake[0];
        for(int i=1;i<snake.size();i++)
            if(head.first == snake[i].first && head.second == snake[i].second){
                isgameover = true;
                return ;
            }
        if(head.first == 0 || head.first == COLS-1 || head.second == 0 || head.second == LINES-1){
            isgameover = true;
            return ;
        }
        pair<int, int> foodPos = food.getPos();
        if(head.first == foodPos.first && head.second == foodPos.second){
            food.changePos();
            pair<int, int> tail = snake[snake.size()-1];
            snake.addBody(tail);
            score.increase(1);
        }
    }

    void drawGameBody(){
        clear();
        box(stdscr, 0, 0);
        score.draw();
        food.draw();
        snake.draw();
        controller.control(snake);
        collisionTest();
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
    bool isgameover;
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