#include <iostream>
#include "Execute.h"

Execute::Execute(std::string n):Component(n) {
    name = n;
    this->add_in_pin("PCin");
    this->add_out_pin("PCout");
}

void Execute::tick(void) {
    Pin * inpin = this->get_in_pin("PCin");
    Pin * outpin = this->get_out_pin("PCout");
    uint16_t val;

    if (inpin) {
        val = inpin->get_val();
    }
    if (outpin) {
        outpin->set_val(val);
        std::cout << "Execute:" << val << std::endl;
    }
}

