#include <SDL2/SDL.h>
#include <string>
#include "../src/GameBody.hpp"
using namespace std;

class OwnClass:public GameBody{
public:
	OwnClass():GameBody("drawTool",500,500,SDL_WINDOW_SHOWN,30){}
	void update() override{
		gbDrawTool dt(win->getRender());
        dt.drawLine(win->getCanva(),0,0,100,100,gbColor(0,0,0,255));
        dt.drawCircle(win->getCanva(), 50, 50, 50, gbColor(255,0,0,255));
        dt.drawRect(win->getCanva(), 100, 100, 50, 60, gbColor(0,255,0,255));
        dt.fillRect(win->getCanva(), 400, 400, 100, 100, gbColor(0,0,255,255));
		dt.drawCircle(win->getCanva(),200,200,100,gbColor(100,100,100,255));
	}
};

RUN_APP(OwnClass);
