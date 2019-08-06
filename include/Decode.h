#pragma once
#include <string>
#include <cstdint>
#include "Component.h"

enum Decode
{
    ADD,
    SUB,
    AND,
    OR,
    COM,
    EOR
};

class Decode: public Component {
public:

    explicit Decode(std::string n);
    
    void tick(void);
private:
    uint16_t val;
};
