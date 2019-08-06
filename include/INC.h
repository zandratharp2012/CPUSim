#pragma once
#include <string>
#include <cstdint>
#include "Component.h"

class INC : public Component {
 public:
    // constructors
    explicit INC(std::string n);

    // mutators
    void tick(void);
 private:
    uint16_t val;
};
