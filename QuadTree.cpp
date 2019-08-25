/*
 QuadTree
 
 author:
 VisualGMQ
 data:
 2019.8.25
 compile:
 g++ QuadTree.cpp -o QuadTree `sdl2-config --libs --cflags` -std=c++11
 */
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#define USE_QUARDTREE

using namespace std;

SDL_Window* window = nullptr;
SDL_Renderer* render = nullptr;
int width = 800;
int height = 800;

class Rect{
public:
    Rect(int x, int y, int w, int h, int dx, int dy, int r=255, int g=255, int b=255){
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        this->dx = dx;
        this->dy = dy;
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = 255;
    }
    
    int getX(){return rect.x;}
    int getY(){return rect.y;}
    int getW(){return rect.w;}
    int getH(){return rect.h;}
    
    void collision(Rect& other){
        if(SDL_HasIntersection(&other.rect, &rect)){
            SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
            SDL_RenderFillRect(render, &rect);
            SDL_RenderFillRect(render, &other.rect);
        }
    }
    
    void draw(){
        SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
        SDL_RenderDrawRect(render, &rect);
    }
    
    void update(){
        rect.x += dx;
        rect.y += dy;
        if(rect.x<0){
            rect.x = 0;
            dx = -dx;
        }
        if(rect.x+rect.w>width){
            rect.x = width-rect.w;
            dx = -dx;
        }
        if(rect.y<0){
            rect.y=0;
            dy = -dy;
        }
        if(rect.y+rect.h>height){
            rect.y = height-rect.h;
            dy = -dy;
        }
        draw();
    }
private:
    int dx;
    int dy;
    SDL_Rect rect;
    SDL_Color color;
};

class QuardTree{
public:
    struct QTNode{
        vector<Rect> nodes;
        QTNode* next1;
        QTNode* next2;
        QTNode* next3;
        QTNode* next4;
        SDL_Rect bound;
        QTNode(int x, int y, int w, int h):next1(nullptr),next2(nullptr),next3(nullptr),next4(nullptr){
            bound.x = x;
            bound.y = y;
            bound.w = w;
            bound.h = h;
        }
    };
    using pQTNode = QTNode*;
    
    QuardTree(vector<Rect>& nrects, int w, int h):rects(nrects),maxnode(3){
        root = new QTNode(0, 0, width, height);
        for(int i=0;i<nrects.size();i++)
            _insert(root, nrects[i]);
    }
    
    void Update(){
        Clear();
        for(int i=0;i<rects.size();i++)
            _insert(root, rects[i]);
        _collision(root);
    }
    
    
    void Clear(){
        if(root->next1)
            _clear(root->next1);
        if(root->next2)
            _clear(root->next2);
        if(root->next3)
            _clear(root->next3);
        if(root->next4)
            _clear(root->next4);
        root->nodes.clear();
    }
    
    ~QuardTree(){
        _clear(root);
        if(root!=nullptr)
            cout<<"root is not deleted"<<endl;
    }
    
private:
    int maxnode;
    vector<Rect>& rects;
    pQTNode root;
    void _clear(pQTNode& node){
        if(node==nullptr)
            return;
        if(node->next1)
            _clear(node->next1);
        if(node->next2)
            _clear(node->next2);
        if(node->next3)
            _clear(node->next3);
        if(node->next4)
            _clear(node->next4);
        delete node;
        node = nullptr;
    }
    
    void _split(pQTNode& node){
        if(!node)
            return;
        SDL_Rect bound = node->bound;
        int halfw = bound.w/2,
            halfh = bound.h/2;
        if(!node->next1)
            node->next1 = new QTNode(bound.x+halfw, bound.y, halfw, halfh);
        if(!node->next2)
            node->next2 = new QTNode(bound.x, bound.y, halfw, halfh);
        if(!node->next3)
            node->next3 = new QTNode(bound.x, bound.y+halfh, halfw, halfh);
        if(!node->next4)
            node->next4 = new QTNode(bound.x+halfw, bound.y+halfh, halfw, halfh);
    }
    
    bool _isleaf(pQTNode& node){
        return !(node->next1 || node->next2 || node->next3 || node->next4);
    }
    
    void _fixnode(pQTNode& node){
        if(node==nullptr)
            return;
        if(_isleaf(node)){
            for(auto it=node->nodes.begin();it!=node->nodes.end();it++){
                Rect rect = *it;
                SDL_Rect bound = node->bound;
                if(rect.getX()>bound.x+bound.w || rect.getX()+rect.getW()<bound.x || rect.getY()>bound.y+bound.h || rect.getY()+rect.getH()<bound.y){
                    node->nodes.erase(it);
                    _insert(root, rect);
                }
            }
        }else{
            _fixnode(node->next1);
            _fixnode(node->next2);
            _fixnode(node->next3);
            _fixnode(node->next4);
        }
    }
    
    void _deliver(pQTNode& node){
        if(node->nodes.size() <= maxnode)
            if(_isleaf(node))
                return;
        
        if(_isleaf(node))
            _split(node);
        vector<Rect> temp = node->nodes;
        node->nodes.clear();
        for(int i=0;i<temp.size();i++){
            int top = temp[i].getY(),
                bottom = temp[i].getY() + temp[i].getH(),
                left = temp[i].getX(),
                right = temp[i].getX() + temp[i].getW();
            int x = node->bound.x,
                y = node->bound.y,
                w = node->bound.w,
                h = node->bound.h,
                halfw = node->bound.w/2,
                halfh = node->bound.h/2;
            if(left>=x+halfw && right<=x+w && top>=y && bottom<=y+halfh)
                node->next1->nodes.push_back(temp[i]);
            else if(left>=x && right<=x+halfw && top>=y && bottom<=y+halfh)
                node->next2->nodes.push_back(temp[i]);
            else if(left>=x && right<=x+halfw && top>=y+halfh && bottom<=y+h)
                node->next3->nodes.push_back(temp[i]);
            else if(left>=x+halfw && right<=x+w && top>=y+halfh && bottom<=y+h)
                node->next4->nodes.push_back(temp[i]);
            else
                node->nodes.push_back(temp[i]);
        }
        _deliver(node->next1);
        _deliver(node->next2);
        _deliver(node->next3);
        _deliver(node->next4);
    }
    
    void _insert(pQTNode& node, Rect& rect){
        node->nodes.push_back(rect);
        _deliver(node);
    }
    
    void _collision(pQTNode& node){
        if(node == nullptr)
            return;
        if(_isleaf(node)){
            /*
             下面两行添加之后bug就消失了。。。
             */
            if(node->nodes.size() == 0)
                return;
            /*TODO 这里的循环很迷，有时候调试会发现明明i以及大于node->nodes.size()了，但是还在增加，导致了死循环。解决这个问题！
             经证实不是node->nodes.size()的问题，其值是对的。
             很可能是递归造成的错误
             */
            for(int i=0;i<node->nodes.size()-1;i++)
                for(int j=i+1;j<node->nodes.size();j++){
                    node->nodes[i].collision(node->nodes[j]);
                }
            return;
        }
        _collision(node->next1);
        _collision(node->next2);
        _collision(node->next3);
        _collision(node->next4);
    }
};

int main(int argc, char** argv){
    srand(time(nullptr));
    SDL_Init(SDL_INIT_EVENTS|SDL_INIT_VIDEO);
    window = SDL_CreateWindow("QuadTree", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    
    vector<Rect> rects;
    for(int i=0;i<20;i++)
        rects.push_back(Rect(rand()%(width-20), rand()%(height-20), 20, 20, rand()%10+1, rand()%10+1));
    
    QuardTree tree(rects, width, height);
    
    bool isquit = false;
    while(!isquit){
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
        SDL_RenderClear(render);
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    isquit = true;
                    break;
            }
        }
        
        for(int i=0;i<rects.size();i++)
            rects[i].update();
        
#ifdef USE_QUARDTREE
        tree.Update();
#else
        for(int i=0;i<rects.size();i++)
            for(int j=0;j<rects.size();j++){
                if(i!=j)
                    rects[i].collision(rects[j]);
            }
#endif
        
        SDL_Delay(30);
        SDL_RenderPresent(render);
    }
    SDL_Quit();
    return 0;
}
