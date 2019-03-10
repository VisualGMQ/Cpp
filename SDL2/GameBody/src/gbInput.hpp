#ifndef __GB_INPUT__
#define __GB_INPUT__
/** @file gbInput.hpp
 *  @author VisualGMQ
 *  @brief 封装了键盘和鼠标的输入
 */
#include <SDL2/SDL.h>
#include <iostream>
#include "geomentry.hpp"

class gbInput{
public:
	enum MouseButton{
		LEFT_BUTTON = 1,
		MIDDLE_BUTTON,
		RIGHT_BUTTON
	};
	enum MouseState{
		MOUSE_PRESS = 1,
		MOUSE_UP,
		MOUSE_DOWN
	};
	enum KeyState{
		KEYPRESSED,
		KEYDOWN,
		KEYUP
	};
	static void Init();
	static KeyState getKeyState(SDL_Keycode);

	static gbPoint getMousePoint();
	static MouseState getMouseState(MouseButton);
	static void step();
	static void clean();
private:
	static void copyKeyState(Uint8*);
	static Uint8* oldKeyState;  //Scancode
	static Uint8* keyState; //Scancode
	static MouseState oldMouseState[3];
	static MouseState mouseState[3];
};
#endif
