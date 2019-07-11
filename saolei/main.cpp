#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <random>
//#define __DEBUG__
using namespace std;

//TODO implement restart panel and win panel

class UIitem{
public:
    virtual void update(SDL_Renderer* render) = 0;
    virtual void eventHandle(){
        if(event->type == SDL_MOUSEBUTTONDOWN)
            mouseDown(event->button.x, event->button.y);
        if(event->type == SDL_MOUSEBUTTONUP)
            mouseUp(event->button.x, event->button.y);
        if(event->type == SDL_MOUSEMOTION)
            mouseMove(event->button.x, event->button.y);
    }
    int getX(){return rect.x;}
    int getY(){return rect.y;}
    int getWidth(){return rect.w;}
    int getHeight(){return rect.h;}
    void setPosition(int x, int y){rect.x=x;rect.y=y;}
    void resize(int w, int h){rect.h=h;rect.w=w;}
    void setRect(int x, int y, int w, int h){rect.x = x;rect.y = y;rect.h = h;rect.w = w;}
    //listener form Main
    void postEvent(const SDL_Event& nevent){event = &nevent;}
    virtual void mouseDown(int mx, int my) = 0;
    virtual void mouseUp(int mx, int my) = 0;
    virtual void mouseMove(int mx, int my) = 0;
    SDL_Rect getRect(){return rect;}
protected:
    SDL_Rect rect;
    const SDL_Event* event;
};

enum CellType{NO_BOMB, HAS_BOMB};
enum CellState{COVERED, NO_COVERED, HAS_FLAG};

//TODO add picture on surfae
class Cell:public UIitem{
public:
    static void postAllEvents(const SDL_Event& nevent){
        for(int i=0;i<instances.size();i++){
            instances[i]->postEvent(nevent);
            instances[i]->eventHandle();
        }
    }
    
    static Cell* createInstance(CellType ctype){
        Cell* cell = new Cell(ctype);
        instances.push_back(cell);
        return cell;
    }
    
    static void clearInstances(){
        for(int i=0;i<instances.size();i++)
            delete instances[i];
        instances.clear();
    }
    
    Cell(CellType ctype):ismouseon(false),type(ctype),num(0),state(COVERED),surface(nullptr){}
    Cell(CellType ctype, int w, int h):ismouseon(false),type(ctype),num(0),state(COVERED),surface(nullptr){
        resize(w, h);
    }
    Cell(CellType ctype, int x, int y, int w, int h):ismouseon(false),type(ctype),num(0),state(COVERED),surface(nullptr){
        setRect(x, y, w, h);
    }
    void changeType(CellType ctype){type=ctype;}
    CellType getType(){return type;}
    void setState(CellState nstate){
        state = nstate;
    }
    void loadImage(string path){
        if(surface != nullptr)
            SDL_FreeSurface(surface);
        surface = IMG_Load(path.c_str());
    }
    void loadImage(char path[]){
        if(surface != nullptr)
            SDL_FreeSurface(surface);
        surface = IMG_Load(path);
    }
    CellState getState(){return state;}
    void changeNum(int nnum){num = nnum;}
    int getNum(){return num;}
    
    void update(SDL_Renderer* render) override{
        //eventHandle();
        switch(state){
            case COVERED:
                drawCovered(render);
                break;
            case NO_COVERED:
                drawUncovered(render);
                break;
            case HAS_FLAG:
                drawCovered(render);
                break;
        }
    }
    
    ~Cell(){
        SDL_FreeSurface(surface);
    }
private:
    static vector<Cell*> instances;
    CellType type;
    CellState state;
    int num;
    SDL_Surface* surface;
    bool ismouseon;
    void drawCovered(SDL_Renderer* render){
        if(state == HAS_FLAG)
            loadImage("./src/hongqi.png");
        else if(state == COVERED)
            loadImage("./src/but_back.png");
        SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
        SDL_RenderCopy(render, texture, nullptr, &rect);
        SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
        SDL_RenderDrawRect(render, &rect);
        if(ismouseon){
            SDL_SetRenderDrawColor(render, 0, 255, 0, 100);
            SDL_RenderFillRect(render, &rect);
        }else{
            SDL_SetRenderDrawColor(render, 0, 0, 200, 255);
            SDL_RenderDrawRect(render, &rect);
        }
        SDL_DestroyTexture(texture);
    }
    void drawUncovered(SDL_Renderer* render){
        char buff[1024] = {'\0'};
        switch(type){
            case NO_BOMB:
                sprintf(buff, "./src/%d.jpg", num);
                loadImage(buff);
                break;
            case HAS_BOMB:
                loadImage("./src/bomb.jpg");
                break;
        }
        if(surface == nullptr)
            SDL_Log("surface is null");
        else{
            SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
            SDL_RenderCopy(render, texture, nullptr, &rect);
            SDL_DestroyTexture(texture);
        }
        SDL_SetRenderDrawColor(render, 0, 0, 200, 255);
        SDL_RenderDrawRect(render, &rect);
    }
    
    void mouseDown(int mx, int my) override{
        SDL_Point p;
        p.x = mx;
        p.y = my;
        if(SDL_PointInRect(&p, &rect)){
            if(event->button.button == SDL_BUTTON_LEFT && state != HAS_FLAG)
                state = NO_COVERED;
            if(event->button.button == SDL_BUTTON_RIGHT){
                if(state == HAS_FLAG)
                    state = COVERED;
                else if(state == COVERED)
                    state = HAS_FLAG;
            }
        }
    }
    void mouseMove(int mx, int my) override{
        SDL_Point p;
        p.x = mx;
        p.y = my;
        if(SDL_PointInRect(&p, &rect)){
            ismouseon = true;
        }else
            ismouseon = false;
    }
    void mouseUp(int mx, int my) override{}
};

vector<Cell*> Cell::instances = vector<Cell*>();

class Map{
public:
    Map(){}
    Map(int nwidth, int nheight, int nrow, int ncol, int nbn){
        init(nwidth, nheight, nrow, ncol, nbn);
    }
    
    void reinit(){
        Cell::clearInstances();
        map.clear();
        init(width, height, row, col, bombnum);
    }
    
    void init(int width, int height, int row, int col, int bn){
        this->width = width;
        this->height = height;
        this->row = row;
        this->col = col;
        bombnum = bn;
        perwidth = width/col;
        perheight = height/row;
        uncoverd_cellnum = 0;
        for(int i=0;i<row;i++){
            vector<Cell*> inner;
            for(int j=0;j<col;j++){
                Cell* c = Cell::createInstance(NO_BOMB);
                c->setPosition(i*perheight, j*perwidth);
                c->resize(perwidth, perheight);
                inner.push_back(c);
            }
            map.push_back(inner);
        }
        generateBomb(row, col);
        for(int i=0;i<map.size();i++)
            for(int j=0;j<map[0].size();j++)
                calcuNum(i, j);
    }
    
    void generateBomb(int row, int col){
        default_random_engine e;
        e.seed((unsigned int)time(nullptr));
        uniform_int_distribution<int> uidrow(0, row-1);
        uniform_int_distribution<int> uidcol(0, col-1);
        for(int i=0;i<bombnum;i++){
            int x = uidcol(e);
            int y = uidrow(e);
            while(map[x][y]->getType() == HAS_BOMB){
                x = uidcol(e);
                y = uidrow(e);
            }
            map[x][y]->changeType(HAS_BOMB);
        }
    }
    
    void eventHandle(const SDL_Event& event){
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
            int col = event.button.x/perwidth,
            row = event.button.y/perheight;
            //SDL_Log("click row:%d, col:%d", row, col);
            Cell* tmp = map[col][row];
            switch(tmp->getState()){
                case COVERED:
                    if(tmp->getType()==HAS_BOMB){
                        bomb();
                        uncoverd_cellnum = this->row*this->col-bombnum;
                    }
                    else if(tmp->getType()==NO_BOMB && tmp->getNum()==0){
                        floodFill(col, row);
                    }
                    if(tmp->getState() == COVERED)
                        uncoverd_cellnum++;
                    break;
                case NO_COVERED:
                    break;
                case HAS_FLAG:
                    break;
            }
        }
    }
    
    void update(SDL_Renderer* render){
        for(int i=0;i<map.size();i++)
            for(int j=0;j<map[0].size();j++)
                map[i][j]->update(render);
    }
    
    int getRow(){
        return row;
    }
    
    int getCol(){
        return col;
    }
    
    int getBombnum(){
        return bombnum;
    }
    
    int getUncoverdNum(){
        return uncoverd_cellnum;
    }
    
    void debugPrint(){
        cout<<"map:"<<endl;
        cout<<"info: perwidth:"<<perwidth<<", perheight:"<<perheight<<endl;
        for(int i=0;i<map.size();i++){
            for(int j=0;j<map[0].size();j++){
                switch(map[i][j]->getState()){
                    case NO_COVERED:
                        if(map[i][j]->getType() == HAS_BOMB)
                            cout<<"*";
                        if(map[i][j]->getType() == NO_BOMB)
                            cout<<map[i][j]->getNum();
                        break;
                    case COVERED:
                        cout<<'o';
                        break;
                    case HAS_FLAG:
                        cout<<"f";
                        break;
                }
                cout<<',';
                //calcuNum(i, j);
            }
            cout<<endl;
        }
    }
    
    void calcuNum(int row, int col){
        int count = 0;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++){
                if((i==0 && j==0) || map[row][col]->getType()==HAS_BOMB) continue;
                if(row+i>=0 && col+j<map[0].size() && col+j>=0 && row+i<map.size()){
                    //cout<<i<<","<<j<<endl;
                    if(map[row+i][col+j]->getType()==HAS_BOMB)
                        count++;
                }
            }
        map[row][col]->changeNum(count);
        //cout<<row<<','<<col<<endl;
    }
    
    void floodFill(int x, int y){
        //SDL_Log("floodFill row:%d, col:%d", x,y);
        map[x][y]->setState(NO_COVERED);
        uncoverd_cellnum++;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++){
                if( i==0 && j==0) continue;
                if(i+x>=0 && i+x<map.size() && j+y>=0 && j+y<map[0].size()){
                    if(map[i+x][j+y]->getType()==NO_BOMB && map[i+x][j+y]->getState()==COVERED){
                        if(map[i+x][j+y]->getNum()==0){
                            if(i*j==0)
                                floodFill(i+x, j+y);
                        }else{
                            map[i+x][j+y]->setState(NO_COVERED);
                            uncoverd_cellnum++;
                        }
                    }
                }
            }
    }
    
    void bomb(){
        for(int i=0;i<map.size();i++)
            for(int j=0;j<map[0].size();j++)
                map[i][j]->setState(NO_COVERED);
    }
    
    ~Map(){
        Cell::clearInstances();
        map.clear();
    }
private:
    vector<vector<Cell*>> map;
    int bombnum;
    int perwidth;
    int perheight;
    int width;
    int height;
    int row;
    int col;
    int uncoverd_cellnum;
};

enum ButtonID{B_OK, B_CANCEL};

class Button:public UIitem{
public:
    static Button* createInstance(ButtonID bid){
        Button* b = new Button(bid);
        instances.push_back(b);
        return b;
    }
    
    static Button* createInstance(ButtonID bid, int x, int y){
        Button* b = new Button(bid, x, y);
        instances.push_back(b);
        return b;
    }
    
    static Button* createInstance(ButtonID bid, int x, int y, int w, int h){
        Button* b = new Button(bid, x, y, w, h);
        instances.push_back(b);
        return b;
    }
    
    static void clearInstances(){
        for(int i=0;i<instances.size();i++)
            delete instances[i];
        instances.clear();
    }
    
    static void postAllEvents(const SDL_Event& event){
        for(int i=0;i<instances.size();i++){
            instances[i]->postEvent(event);
            instances[i]->eventHandle();
        }
        
    }
    
    Button(ButtonID bid):id(bid),isshow(false),surface(nullptr){
        color.r = 100;
        color.g = 100;
        color.b = 100;
        color.a = 255;
        surface = IMG_Load("./src/flush.png");
    }
    Button(ButtonID bid, int w, int h):id(bid),isshow(false),surface(nullptr){
        rect.w = w;
        rect.h = h;
        color.r = 100;
        color.g = 100;
        color.b = 100;
        color.a = 255;
        surface = IMG_Load("./src/flush.png");
    }
    Button(ButtonID bid, int x, int y, int w, int h):id(bid),isshow(false),surface(nullptr){
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        color.r = 100;
        color.g = 100;
        color.b = 100;
        color.a = 255;
        surface = IMG_Load("./src/flush.png");
    }
    void update(SDL_Renderer* render) override{
        if(isshow){
            SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
            SDL_RenderCopy(render, texture, nullptr, &rect);
            SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
            SDL_RenderFillRect(render, &rect);
            SDL_DestroyTexture(texture);
        }
    }
    void setRelateMap(Map* nmap){
        map = nmap;
    }
    void show(bool s=true){
        isshow = s;
    }
    void eventHandle() override{
        if(isshow){
            if(event->type == SDL_MOUSEBUTTONDOWN)
                mouseDown(event->button.x, event->button.y);
            if(event->type == SDL_MOUSEBUTTONUP)
                mouseUp(event->button.x, event->button.y);
            if(event->type == SDL_MOUSEMOTION)
                mouseMove(event->button.x, event->button.y);
        }
    }
    
    ~Button(){
        SDL_FreeSurface(surface);
    }
private:
    static vector<Button*> instances;
    ButtonID id;
    SDL_Color color;
    Map* map;
    bool isshow;
    SDL_Surface* surface;
    void mouseDown(int mx, int my) override{
        SDL_Point p;
        p.x = mx;
        p.y = my;
        if(SDL_PointInRect(&p, &rect)){
            color.r = 100;
            color.g = 100;
            color.b = 100;
            color.a = 150;
            show(false);
            map->reinit();
        }
    }
    void mouseUp(int mx, int my) override{}
    void mouseMove(int mx, int my) override{
        SDL_Point p;
        p.x = mx;
        p.y = my;
        if(SDL_PointInRect(&p, &rect)){
            color.r = 100;
            color.g = 100;
            color.b = 100;
            color.a = 100;
        }else{
            color.r = 100;
            color.g = 100;
            color.b = 100;
            color.a = 200;
        }
    }
};

vector<Button*> Button::instances = vector<Button*>();

class MessageBox: public UIitem{
public:
private:
};

class Main{
public:
    Main(int argc, char** argv):width(600), height(600), delaytime(1), isquit(false){
        SDL_Init(SDL_INIT_EVERYTHING);
        IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG|IMG_INIT_TIF|IMG_INIT_WEBP);
        window = SDL_CreateWindow("扫雷", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        //SDL_assert(window == nullptr);
        render = SDL_CreateRenderer(window, -1, 0);
        //SDL_assert(render == nullptr);
        paramParse(argc, argv);
        SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
        //map.init(width, height, 20, 20, 50);
        b = Button::createInstance(B_OK);
        b->show(false);
        b->resize(100, 100);
        b->setPosition(width/2-b->getWidth()/2, height/2-b->getHeight()/2);
        b->setRelateMap(&map);
    }
    
    void paramParse(int argc, char** argv){
        if(argc != 1){
            if(argc == 2){
                if(strcpy(argv[1], "eazy"))
                    map.init(width, height, 10, 10, 20);
                if(strcpy(argv[1], "normal"))
                    map.init(width, height, 20, 20, 100);
                if(strcpy(argv[1], "hard"))
                    map.init(width, height, 30, 30, 300);
            }
            if(argc == 4){
                stringstream ss;
                int row, col, bn;
                ss<<argv[1];
                ss>>row;
                ss<<argv[2];
                ss>>col;
                ss<<argv[3];
                ss>>bn;
                map.init(width, height, row, col, bn);
            }
        }else
            map.init(width, height, 20, 20, 50);
            
    }
    
    void handleEvent(){
        while(SDL_PollEvent(&event)){
            map.eventHandle(event);
            Cell::postAllEvents(event);
            Button::postAllEvents(event);
            if(event.type == SDL_QUIT)
                isquit = true;
        }
    }
    
    void clearScreen(int r, int g, int b){
        SDL_SetRenderDrawColor(render, r, b, g ,255);
        SDL_RenderClear(render);
    }
    
    void update(){
        map.update(render);
        if(map.getUncoverdNum() == map.getRow()*map.getCol()-map.getBombnum())
            b->show();
        b->update(render);
    }
    
    void step(){
        update();
    }
    
    void run(){
        while(!isquit){
            clearScreen(255, 255 ,255);
            handleEvent();
            step();
            SDL_RenderPresent(render);
            SDL_Delay(delaytime);
        }
    }
    ~Main(){
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(render);
        IMG_Quit();
        Cell::clearInstances();
        Button::clearInstances();
        SDL_Quit();
    }
private:
    SDL_Window* window;
    SDL_Renderer* render;
    SDL_Event event;
    bool isquit;
    int width;
    int height;
    int delaytime;
    Map map;
    Button* b;
};

int main(int argc, char** argv){
#ifndef __DEBUG__
    //game run
    Main gamebody(argc, argv);
    gamebody.run();
#else
    //debug module
    Map map(400, 400, 10, 10, 10);
    map.debugPrint();
#endif
    return 0;
}
