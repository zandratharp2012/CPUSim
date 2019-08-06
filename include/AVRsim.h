#pragma once
#include <string>
#include <cstdint>
#include "Fetch.h"
#include "Decode.h"
#include "Execute.h"
#include "Store.h"
#include "Wire.h"

class AVRsim {
 public:
    // constructor
    explicit AVRsim(std::string name);

    // accessors
    std::string get_name(void);
    uint16_t get_pcnext(void);

    // mutators
    void run(void);
    void set_steps(int nsteps);
    void set_debug(void);
    void tick(void);

 private:
    std::string name;
    bool debug;
    int steps;
    void build(void);
};

