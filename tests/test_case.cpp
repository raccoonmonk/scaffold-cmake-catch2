#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "Library.h"

SCENARIO("Is even", "[General]")
{
    REQUIRE(meaningOfLife() % 2 == 0);
}
