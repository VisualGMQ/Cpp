#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/gbWindow.hpp"
#include "../src/geomentry.hpp"

TEST_CASE("gbWindow","[gbWindow]"){
	gbWindow window("test title",700,600,SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	SECTION("test gbWindow's get* function"){
		gbSize size(700,600);
		REQUIRE(window.getSize() == size);
		REQUIRE(window.getTitle() == "test title");
		REQUIRE(window.getMode() == (SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE));
	}
	SECTION("test set* function"){
		window.setTitle("changed");
		REQUIRE(window.getTitle() == "changed");
		window.setBrightness(0.5);
		REQUIRE(window.getBrightness() == 0.5);
	}
}
