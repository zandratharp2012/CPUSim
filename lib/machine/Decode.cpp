#include <iostream>
#include <string>
#include "Decode.h"


// Constructor
Decode::Decode(std::string n):Component(n) {
    this->add_in_pin("IN1");
    this->add_in_pin("IN2");
    this->add_in_pin("AOP");
    this->add_out_pin("OUT");
    val = 0;
}

void Decode::tick(void) {
    Pin *in1pin = this->get_in_pin("IN1");
    Pin *in2pin = this->get_in_pin("IN2");
    Pin *aoppin = this->get_in_pin("AOP");
    Pin *outpin = this->get_out_pin("OUT");
    uint16_t ival1, ival2, aop, oval;
    
    try {
        aop = aoppin->get_val();
        ival1 = in1pin->get_val();
        ival2 = in2pin->get_val();
    }
    catch (std::exception & e) {
        std::cout
        << "Decode pins not configured: "
        << e.what()
        << std::endl;
    }
    switch (aop) {
        case ADD:
            oval = ival1 + ival2;
            break;
        case SUB:
            oval = ival1 - ival2;
            break;
        case COM:
            oval = ~ival1;
            break;
        case AND:
            oval = ival1 & ival2;
            break;
        case OR:
            oval = ival1 | ival2;
            break;
        case EOR:
            oval = ival1 ^ ival2;
            break;
    }
    try {
        outpin->set_val(oval);
    }
    catch(std::exception e) {
        std::cout
        << "Decode out pin not configured"
        << e.what()
        << std::endl;
    }
}
