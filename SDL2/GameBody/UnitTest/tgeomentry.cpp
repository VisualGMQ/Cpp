#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../src/geomentry.hpp"

TEST_CASE("test gbRect","[gbRect]"){
	gbRect rect(10,20,40,50);
	SECTION("test get* & set* function"){
			REQUIRE(rect.getX() == 10);
			REQUIRE(rect.getY() == 20);
			REQUIRE(rect.getWidth() == 40);
			REQUIRE(rect.getHeight() == 50);
			rect.setX(5);
			REQUIRE(rect.getX() == 5);
			rect.setY(10);
			REQUIRE(rect.getY() == 10);
			rect.setWidth(12);
			REQUIRE(rect.getWidth() == 12);
			rect.setHeight(18);
			REQUIRE(rect.getHeight() == 18);
	}
	SECTION("test logic operator"){
		const gbRect rect2(10,20,40,50);
		REQUIRE(rect == rect2);
		REQUIRE_FALSE(rect != rect2);
	}
}
