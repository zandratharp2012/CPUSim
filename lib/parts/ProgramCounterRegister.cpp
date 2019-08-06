#include "ProgramCounterRegister.h"
#include<iostream>
include<string>

ProgramCounterRegister::ProgramCounterRegister()
{
    this->inputpin(items[i]);
    this->outputpin(items[i]);
    val=0;
}

void ProgramCounterRegister::tick(void)
{
    Pin *inpin = this->get_in_pin("IN");
    Pin *outpin = this->get_out_pin("OUT");
    uint8_t ival, oval;
    
    oval = val;
    if (inpin) {
        val = inpin->get_val();
    }
    if (outpin) {
        outpin->set_val(oval);
    }
}

}
