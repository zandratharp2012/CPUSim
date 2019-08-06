#include <iostream>
#include "Store.h"

Store::Store(std::string n):Component(n) {
    name = n;
    this->add_in_pin("PCin");
    this->add_out_pin("PCout");
}

void Store::tick(void) {
    Pin * inpin = this->get_in_pin("PCin");
    Pin * outpin = this->get_out_pin("PCout");
    uint16_t val;

    if (inpin) {
        val = inpin->get_val();
    }
    if (outpin) {
        std::cout << "Store:" << val << std::endl;
        outpin->set_val(val);
    }
}

