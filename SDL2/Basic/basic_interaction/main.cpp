#include <SDL2/SDL_image.h>

bool isquit;
int rangle = 0;
const Uint8* key = nullptr;
SDL_Window* win = nullptr;
SDL_Renderer* render = nullptr;
SDL_Surface* surface = nullptr;
SDL_Texture* texture = nullptr;
SDL_Rect destrect;
SDL_Event event;

bool init();
void update();
void clean();

int main(int argc,char* args[]){
	if(init()==false)
		return -1;
	SDL_Log("%s",SDL_GetPlatform());
	while(!isquit)
		update();
	clean();
	return 0;
}

bool init(){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0)
		return false;
	if((win = SDL_CreateWindow("basic_interaction",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,700,700,SDL_WINDOW_RESIZABLE))==nullptr)
		return false;
	if((render = SDL_CreateRenderer(win,-1,0))==nullptr)
		return false;
	surface = IMG_Load("1.jpeg");
	if(surface == nullptr){
		SDL_Log("image can't be load");
		return false;
	}
	SDL_SetColorKey(surface,SDL_TRUE,0xffffff);
	texture = SDL_CreateTextureFromSurface(render,surface);
	SDL_QueryTexture(texture,nullptr,nullptr,&destrect.w,&destrect.h);
	SDL_SetRenderDrawColor(render,0,0,100,255);
	destrect.w/=3;
	destrect.h/=3;
	destrect.x=0;
	destrect.y=200;
	return true;	
}

void update(){
	SDL_RenderClear(render);
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT)
			isquit=true;	
	}		
	key = SDL_GetKeyboardState(nullptr);
	if(key[SDL_SCANCODE_A])
		destrect.x-=10;
	if(key[SDL_SCANCODE_D])
		destrect.x+=10;
	if(key[SDL_SCANCODE_J])
		rangle-=5;
	if(key[SDL_SCANCODE_L])
		rangle+=5;
	if(key[SDL_SCANCODE_ESCAPE])
		isquit=true;
	if(key[SDL_SCANCODE_H]){
		rangle=0;
		destrect.x=0;
		destrect.y=200;
	}
	if(destrect.x<0)
		destrect.x=0;
	if(destrect.x+destrect.w>700)
		destrect.x=700-destrect.w;

	SDL_RenderCopyEx(render,texture,nullptr,&destrect,rangle,nullptr,SDL_FLIP_NONE);
	SDL_RenderPresent(render);
	SDL_Delay(30);
}

void clean(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(win);
	SDL_Quit();
}
