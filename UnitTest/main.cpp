#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <iostream>
using namespace std;

TEST_CASE("test max function","[max]"){
	int i=0;
	SECTION("case 3"){
		i = 3;
		REQUIRE(i == 3);
	}
	SECTION("case 5"){
		i = 5;
		REQUIRE(i == 5);
	}
	SECTION("case 0"){
		REQUIRE(i == 5);
	}
}
