#pragma once
#include <string>
#include "Component.h"

class Inverter : public Component {
public:
    // constructors
    explicit Inverter(std::string n);
    
    // mutators
    void tick(void);
};
