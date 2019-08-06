#pragma once
#include <string>
#include <cstdint>
#include "Component.h"

class ProgramCounterRegister: public Component {
public:
    // constructors
    explicit ProgramCounterRegister(std::string n);
    
    // mutators
    void tick(void);
private:
    uint16_t val;
};
