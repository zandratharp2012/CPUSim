#include <iostream>
#include <string>
#include "AVRsim.h"
#include "Pin.h"

// create objects for each stage
Fetch fetch("fetch");
Decode decode("decode");
Execute execute("execute");
Store store("store");

// create wires to hook them together
Wire w1("W1");
Wire w2("W2");
Wire w3("W3");
Wire w4("W4");

AVRsim::AVRsim(std::string n, bool dbg) {
    debug = dbg;
    name = n;
    build();
}

std::string AVRsim::get_name(void) {
    return name;
}

void AVRsim::run(bool guienabled) {
    std::cout
    << "AVRsim running (gui enabled: "
    << guienabled
    << ")" << std::endl;
}

void AVRsim::build(void) {
    if (debug) {
        std::cout << "attaching wires" << std::endl;
    }
    w1.attach_driven(fetch.get_out_pin("PCout"));
    w1.attach_drives(decode.get_in_pin("PCin"));
    w2.attach_driven(decode.get_out_pin("PCout"));
    w2.attach_drives(execute.get_in_pin("PCin"));
    w3.attach_driven(execute.get_out_pin("PCout"));
    w3.attach_drives(store.get_in_pin("PCin"));
    w4.attach_driven(store.get_out_pin("PCout"));
    w4.attach_drives(fetch.get_in_pin("PCin"));
}

uint16_t AVRsim::get_pcnext(void) {
    Pin * pcnext = fetch.get_in_pin("PCin");
    if (debug) std::cout << "pcnext" << pcnext << std::endl;
    return pcnext ? pcnext->get_val() : 0;
}

void AVRsim::tick(void) {
    fetch.tick();
    w1.tock();
    decode.tick();
    w2.tock();
    execute.tick();
    w3.tock();
    store.tick();
    w4.tock();
    fetch.tick();
    w1.tock();
    decode.tick();
    w2.tock();
}

