// Copyright 2019 Zandra Tharp 
#include "INC.h"
#include <iostream>
#include <string>

// constructor
INC::INC(std::string n):Component(n) {
    this->add_in_pin("IN");
    this->add_out_pin("OUT");
    val = 0;
}

// TICK: perform component processing
void INC::tick(void) {
    Pin *inpin = this->get_in_pin("IN");
    Pin *outpin = this->get_out_pin("OUT");
    uint16_t ival, oval;
    val = inpin->get_val();
    oval = (val + 1) % 65536;
    if (inpin) {
        val = inpin->get_val();
    }
    if (outpin) {
        outpin->set_val(oval);
    }
}

