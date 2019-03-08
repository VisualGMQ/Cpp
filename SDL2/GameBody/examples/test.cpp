#include "../src/GameBody.hpp"

class OwnGame : public GameBody{
public:
	OwnGame():GameBody("test",700,700,SDL_WINDOW_RESIZABLE,30){};
};

RUN_APP(OwnGame)
