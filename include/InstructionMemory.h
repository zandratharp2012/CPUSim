#pragma once
#include <string>
#include <cstdint>
#include "Component.h"

class InstructionMemory : public Component {
public:
    // constructors
    explicit InstructionMemory(std::string n);
    
    // mutators
    void tick(void);
    void load(std::string fn);
    
private:
    uint16_t val;
};
