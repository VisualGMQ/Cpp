#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int Width=700;
const int Height=700;
const int DELAYTIME=30;
int rangle=0;
bool isquit=false;
SDL_Rect destrect,srcrect;
SDL_Surface* surface = nullptr;
SDL_Texture* texture = nullptr,*alphatexture = nullptr;
SDL_Window* window = nullptr;
SDL_Renderer* render= nullptr;
SDL_Event event;
bool init();
void renderScreen();
void handleEvnet();
void update();
void clean();

int main(int argc,char* args[]){
	if(init()==false)
		return -1;
	while(!isquit){
		renderScreen();
		update();	
	}
	clean();
	return 0;
}

bool init(){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		SDL_Log("can't init SDL");
		return false;
	}
	if((window = SDL_CreateWindow("Image Transform",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Width,Height,SDL_WINDOW_RESIZABLE))==nullptr){
		SDL_Log("Window can't be created");
		return false;
	}
	if((render = SDL_CreateRenderer(window,-1,0))==nullptr){
		SDL_Log("can't create renderer");
		return false;
	}
	surface = IMG_Load("1.jpeg");
	if(surface == nullptr)
		SDL_Log("can't open the 1.jpeg");
	else
		texture = SDL_CreateTextureFromSurface(render,surface);
	SDL_QueryTexture(texture,nullptr,nullptr,&srcrect.w,&srcrect.h);
	SDL_SetColorKey(surface,SDL_TRUE,0xffffff);
	alphatexture = SDL_CreateTextureFromSurface(render,surface);
	destrect=srcrect;
	srcrect.x=srcrect.y=0;
	destrect.x=destrect.y=100;
	destrect.w/=2;
	destrect.h/=2;
	return true;

}

void renderScreen(){
	SDL_SetRenderDrawColor(render,0,0,255,255);
	SDL_RenderClear(render);
}

void handleEvent(){
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT)
			isquit=true;
	}
}

void update(){
	handleEvent();
	destrect.x=0;
	destrect.y=100;
	SDL_RenderCopy(render,texture,&srcrect,&destrect);
	destrect.x=200;
	SDL_RenderCopyEx(render,texture,&srcrect,&destrect,0,nullptr,SDL_FLIP_HORIZONTAL);
	destrect.x=400;
	SDL_Point p={(destrect.x+destrect.w)/2,(destrect.y+destrect.h)/2};
	SDL_RenderCopyEx(render,texture,&srcrect,&destrect,-30,nullptr,SDL_FLIP_NONE);
	destrect.y=300;
	SDL_RenderCopyEx(render,texture,&srcrect,&destrect,rangle,nullptr,SDL_FLIP_NONE);
	rangle+=2;
	destrect.x=100;
	destrect.y=400;
	SDL_RenderCopy(render,alphatexture,nullptr,&destrect);
	SDL_Delay(DELAYTIME);
	SDL_RenderPresent(render);
}

void clean(){
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
