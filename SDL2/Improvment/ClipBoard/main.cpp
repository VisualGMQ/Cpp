#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

int main(int argc,char** argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	if(SDL_HasClipboardText()){
		cout<<"剪切板里面有东西:";
		cout<<SDL_GetClipboardText()<<endl;
	}else
		cout<<"剪切板里面没有东西"<<endl;
	SDL_SetClipboardText("Setted somthing");
	cout<<"我在剪切板里面放了一些文本，你可以粘贴到任何文本编辑器里面看一下"<<endl;
	return 0;
}
