#pragma once
#include <string>
#include "Component.h"
#include "MUX2.h"
#include "ProgramCounterRegister.h"
#include "InstructionMemory.h"
#include "INC.h"

class Fetch : public Component {
public:
    explicit Fetch(std::string name);
    void tick(void);
    
private:
    void build(void);
    std::string name;
};



