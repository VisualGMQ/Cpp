#include "gbInput.hpp"

Uint8* gbInput::oldKeyState = nullptr;
Uint8* gbInput::keyState = new Uint8[sizeof(SDL_NUM_SCANCODES-SDL_SCANCODE_UNKNOWN+1)];
gbInput::MouseState gbInput::oldMouseState[3]={MOUSE_UP,MOUSE_UP,MOUSE_UP};
gbInput::MouseState gbInput::mouseState[3]={MOUSE_UP,MOUSE_UP,MOUSE_UP};

void gbInput::Init(){
		gbInput::copyKeyState(gbInput::oldKeyState);
}

void gbInput::copyKeyState(Uint8* key){
	const Uint8* tmp = SDL_GetKeyboardState(nullptr);
	for(int i = SDL_SCANCODE_UNKNOWN;i <= SDL_NUM_SCANCODES;i++)
			key[i] = tmp[i];
}

void gbInput::step(){
	//key state
	const Uint8* newKeyState = SDL_GetKeyboardState(nullptr);
	for(int i = 0;i < sizeof(SDL_Scancode)/newKeyState[0];i++)	
			if(newKeyState[i]==1 && oldKeyState[i]==0)
					keyState[i]=KeyState::KEYDOWN;
			else if(newKeyState[i]==0 && oldKeyState[i]==1)
					keyState[i]=KeyState::KEYUP;
			else
					keyState[i]=KeyState::KEYPRESSED;
	for(int i = SDL_SCANCODE_UNKNOWN;i <= SDL_NUM_SCANCODES;i++)
			gbInput::oldKeyState[i] = newKeyState[i];

	//mouse state
	int newButton = SDL_BUTTON(SDL_GetMouseState(nullptr,nullptr));	
	if(gbInput::oldMouseState[(MouseState)(newButton-1)]==0)
			gbInput::mouseState[(MouseState)(newButton-1)]=MOUSE_DOWN;
	else if(gbInput::oldMouseState[(MouseState)(newButton-1)]==1)
			gbInput::mouseState[(MouseState)(newButton-1)]=MOUSE_PRESS;
	if(newButton == 1){
		gbInput::mouseState[(MouseState)1]=MouseState::MOUSE_UP;
		gbInput::mouseState[(MouseState)2]=MouseState::MOUSE_UP;
	}else if(newButton == 2){
		gbInput::mouseState[(MouseState)0]=MouseState::MOUSE_UP;
		gbInput::mouseState[(MouseState)2]=MouseState::MOUSE_UP;
	}else{
		gbInput::mouseState[(MouseState)0]=MouseState::MOUSE_UP;
		gbInput::mouseState[(MouseState)1]=MouseState::MOUSE_UP;
	}	
}

gbInput::KeyState gbInput::getKeyState(SDL_Keycode key){
	return (KeyState)gbInput::keyState[SDL_GetScancodeFromKey(key)];
}

gbPoint gbInput::getMousePoint(){
	int x,y;
	SDL_GetMouseState(&x,&y);
	gbPoint point(x,y);
	return point;
}

gbInput::MouseState gbInput::getMouseState(MouseButton button){
	return gbInput::mouseState[(MouseState)(button - 1)];
}

void gbInput::clean(){
	delete[] gbInput::keyState;
}
