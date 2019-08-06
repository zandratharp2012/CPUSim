#include <catch.hpp>
#include "AVRsim.h"

const std::string simname = "avrsim";
TEST_CASE("test AVRsim constructor", "[machine]"){
    AVRsim avrsim(simname);
    REQUIRE(avrsim.get_name() == simname);
}

TEST_CASE("test AVRsim PCnext function", "[machine]"){
    AVRsim avrsim(simname);
    uint16_t val = avrsim.get_pcnext();
    avrsim.tick();
    REQUIRE(avrsim.get_pcnext() == val+1);
}
