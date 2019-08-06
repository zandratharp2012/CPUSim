// Copyright 2019 Zandra Tharp 
#include <catch.hpp>
#include "Machine.h"

TEST_CASE( "test machine constructor", "machine" ){
    const std::string name = "TinySim";
    Machine sim(name);
    REQUIRE(sim.get_name() == name);
}
