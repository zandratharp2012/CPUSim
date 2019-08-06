#pragma once
#include "SevenSeg.h"

class HexBar {
 public:
    HexBar();
    void set_pos(int x, int y);
    void set_value(uint16_t val);
    void draw(void);
 private:
    int x, y;
    ColorName bg_color;
    ColorName led_on_color;
    ColorName led_off_color;
};
