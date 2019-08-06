#pragma once
#include <string>
#include "Component.h"

class Execute : public Component {
 public:
    explicit Execute(std::string name);
    void tick(void);

 private:
    std::string name;
};



