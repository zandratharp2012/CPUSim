// Copyright 2019 Roie R. Black
#include "LEDbar.h"
#include "Graphics.h"
#include <iostream>

// constructor
LEDbar::LEDbar() {
    led_on_color = RED;
    led_off_color = GREEN;
    bg_color = GREEN;
    x = 50;
    y = 50;
    width = 20;
    height = 160;
    bits = 0b00110011;
}

// mutators

void LEDbar::set_on(int bval) {
    bits = bval;
}

int LEDbar::get_bits(void) {
    return bits;
}

void LEDbar::set_led_on_color(ColorName c) {
    led_on_color = c;
}

void LEDbar::set_led_off_color(ColorName c) {
    led_off_color = c;
}

void LEDbar::set_pos(int lx, int ly) {
        x = lx;
        y = ly;
}

void LEDbar::draw() {
    setColor(bg_color);
    drawFilledBox(x, y, x+width, y+height);
    bool on[8];
    on[0] = (bits & 0b00000001) > 0;
    on[1] = (bits & 0b00000010) > 0;
    on[2] = (bits & 0b00000100) > 0;
    on[3] = (bits & 0b00001000) > 0;
    on[4] = (bits & 0b00010000) > 0;
    on[5] = (bits & 0b00100000) > 0;
    on[6] = (bits & 0b01000000) > 0;
    on[7] = (bits & 0b10000000) > 0;

    int xo = x + width / 2;
    int yo = y + width / 2;
    int r = width * 0.3;
    for (int i = 0; i < 8; i++) {
        setColor(on[i] ? led_on_color : led_off_color);
        drawFilledCircle(xo, yo, r);
        yo += width;
    }
}
