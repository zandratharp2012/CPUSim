// Copyright 2019 Rie R. Black
#include "HexBar.h"
#include "SevenSeg.h"

SevenSeg disp1, disp2, disp3, disp4;

HexBar::HexBar() {
    x = 0;
    y = 0;
    bg_color = GREEN;
    led_on_color = RED;
    led_off_color = GREEN;
}

void HexBar::set_pos(int x, int y) {
    disp4.set_pos(x, y);
    disp3.set_pos(x + 80, y);
    disp2.set_pos(x + 160, y);
    disp1.set_pos(x + 240, y);
}

void HexBar::draw(void) {
    disp1.draw();
    disp2.draw();
    disp3.draw();
    disp4.draw();
}

void HexBar::set_value(uint16_t val) {
    // display val in hex
    int d1 = val & 0x000f;
    int d2 = (val >> 4) & 0x000f;
    int d3 = (val >> 8) & 0x000f;
    int d4 = (val >> 12);
    disp4.set_hex_digit(d4);
    disp3.set_hex_digit(d3);
    disp2.set_hex_digit(d2);
    disp1.set_hex_digit(d1);
}
