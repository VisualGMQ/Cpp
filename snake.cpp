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

const int DELAY_TIME = 5;
const char SNAKE_BODY = 'S';
const char FOOD = 'D';

vector<pair<int, int>> snake;
pair<int, int> foodPos;
enum Direction{LEFT, RIGHT, TOP, BOTTOM};
Direction direction = LEFT;
int score = 0;
bool isgameover = false;

void init_config();
void init_game();
void drawWelcome();
void changeFood();
void intputKey();
void collisionTest();
void drawFood();
void drawSnake();
void drawScore();
void snakeStep();
void gameloop();
void gameOver();

int main(){
    initscr();
    if(has_colors() == FALSE){
        endwin();
        return -1;
    }
    start_color();
    init_config(); 
    init_game();
    drawWelcome();
    gameloop();
    gameOver();
    endwin();
    return 0;
}

void intputKey(){
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
}

void changeFood(){
    srand(time(nullptr));
    int x = rand()%(COLS-1-1)+1;
    int y = rand()%(LINES-1-1)+1;
    while(!mvinch(y, x)){
        int x = rand()%(COLS-1-1)+1;
        int y = rand()%(LINES-1-1)+1;
    }
    foodPos = make_pair(x, y);
}

void drawFood(){
    attron(COLOR_PAIR(2));
    mvaddch(foodPos.second, foodPos.first, FOOD);
    attroff(COLOR_PAIR(2));
}

void drawScore(){
    attron(COLOR_PAIR(1));
    mvprintw(0, 0, "score: %d", score);
    attroff(COLOR_PAIR(1));
}

void drawSnake(){
    attron(COLOR_PAIR(3)|A_BOLD);
    for(int i=0;i<snake.size();i++){
        #ifdef DEBUG_SNAKE
        mvprintw(i, 0, "snake[%d]: x->%d, y->%d", i, snake[i].first, snake[i].second);
        #endif
        mvaddch(snake[i].second, snake[i].first, SNAKE_BODY);
    }
    attroff(COLOR_PAIR(3)|A_BOLD);
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
    if(head.first == foodPos.first && head.second == foodPos.second){
        changeFood();
        pair<int, int> tail = *(snake.end()-1);
        snake.push_back(tail);
        score++;
    }
}

void init_game(){
    snake.push_back(make_pair(COLS/2, LINES/2));
    changeFood();
}

void init_config(){
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  //text color, score color
    init_pair(2, COLOR_BLUE, COLOR_BLACK);   //food color
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); //snake color
    init_pair(4, COLOR_RED, COLOR_BLACK);    //game over text
    curs_set(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
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

void gameloop(){
    halfdelay(DELAY_TIME);
    while(!isgameover){
        clear();
        box(stdscr, 0, 0);
        drawScore();
        drawFood();
        drawSnake();
        intputKey();
        snakeStep();
        #ifdef DEBUG_SNAKE
        mvprintw(LINES-1, 0, "count:%d", countnum++);
        #endif
        refresh();
    }
}

void snakeStep(){
    collisionTest();
    snake.pop_back();
    pair<int, int> head = snake[0];
    if(direction == LEFT)
        head.first--;
    else if(direction == RIGHT)
        head.first++;
    else if(direction == TOP)
        head.second--;
    else
        head.second++;
    snake.insert(snake.begin(), head);
}

void gameOver(){
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