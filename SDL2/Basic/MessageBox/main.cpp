#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

bool isquit=false;
int scene = 1;
bool init();
void update();
void clean();
SDL_Window* win = nullptr;
SDL_Renderer* render = nullptr;
SDL_Event event;
SDL_MessageBoxData MBFlag;
SDL_MessageBoxButtonData buttons[]={
	{SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "return"},
	{SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "escape"},
	{0										, 2, "button3"}
};

int main(){
	if(init()==false)
		return -1;
	while(!isquit)
		update();
	clean();
	return 0;
}

bool init(){
	if(SDL_Init(SDL_INIT_EVERYTHING)<0)
		return false;
	if((win = SDL_CreateWindow("MessageBox",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,SDL_WINDOW_RESIZABLE))==nullptr)
		return false;
	if((render = SDL_CreateRenderer(win,-1,0))==nullptr)
		return false;
	MBFlag.window = NULL;
	MBFlag.title = "user define msgBox";
	MBFlag.message = "this is user default message";
	MBFlag.numbuttons = 3;
	MBFlag.colorScheme = NULL;
	MBFlag.buttons = buttons;
	MBFlag.flags = SDL_MESSAGEBOX_INFORMATION;
	return true;
}

void update(){
	while(SDL_PollEvent(&event)){
		if(event.type==SDL_QUIT)
			isquit=true;
	}
	switch(scene){
		case 1:
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Infomation Box","this is a infomation box",win);
			scene++;
			break;
		case 2:
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"error Box","this is a error  box",win);
			scene++;
			break;
		case 3:
			int buttonid;
			SDL_ShowMessageBox(&MBFlag, &buttonid);
			scene++;
			break;
	}
}

void clean(){
	SDL_Quit();
}
