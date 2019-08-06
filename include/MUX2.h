#pragma once
#include <string>
#include "Component.h"

class MUX2 : public Component {
 public:
    explicit MUX2(std::string name);
    void tick();
};
