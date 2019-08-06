#include <iostream>
#include "Fetch.h"
#include "MUX2.h"
#include "Wire.h"
#include "Pin.h"
#include "ProgramCounterRegister.h"
#include "InstructionMemory.h"

Fetch::Fetch(std::string n):Component(n) {
    name = n;
    this->add_in_pin("PCnext");
    this->add_out_pin("INS1");
    this->add_out_pin("INS2");
    this->add_out_pin("PC");
}

void Fetch::build(void)
{
    std::cout << "assembling fetch unit" << std::endl;
    // create all needed parts
    Pin zero("zero");
             Mux2 mux("MUX2");
             PC pc("PC");
             IM im("IM");
             
             // create wires
             Wire w1("W1");
             Wire w2("W2");
             Wire w3("W3");
             Wire w4("W4");
             Wire w5("W5");
             Wire w6("W6");
             
             // connect everything
             //  attach reset source to mux
             w1.attach_driven(zero.get_in_pin("zero"));
             w1.attach_drives(mux.get_in_pin("IN1"));
             
             // attach PCnext line to PC register
             Wire w2("W2");
             w2.attach_driven(get_out_pin(mux.get_out_pin("OUT"));
                              w2.attach_drives(pc.get_in_pin("IN"));
}

