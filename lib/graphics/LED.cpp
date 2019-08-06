// Copyright 2019 Roie R. Black
#include "LED.h"
#include "Graphics.h"
#include <iostream>
#define font GLUT_BITMAP_9_BY_15

// constructor
LED::LED() {
    state = true;
    led_on_color = RED;
    led_off_color = GREEN;
    label_on = true;
    label_color = BLUE;
    label = "F";
    x = 50;
    y = 50;
    size = 24;
}

// mutators
void LED::set_size(int s) {
    size = s;
}

void LED::set_on_color(ColorName c) {
    led_on_color = c;
}

void LED::set_label_color(ColorName c) {
    label_color = c;
}

void LED::set_label(std::string l ) {
    label = l;
}

void LED::set_off_color(ColorName c) {
    led_off_color = c;
}

void LED::set_pos(int lx, int ly) {
        x = lx;
        y = ly;
}

void LED::toggle() {
    state = !state;
}

void LED:: set_state(bool s) {
    state = s;
}

void LED::drawLabel(int x, int y) {
    int j = label.length();
    int vw = (j * 9) / 2;
    int vh = 5;
    setColor(label_color);
    glRasterPos2i(x - vw, y - vh);
    for (int i = 0; i < j; i++) {
        glutBitmapCharacter(font, label[i]);
    }
}

void LED::draw() {
    ColorName color;
    state ? color = led_on_color : color = led_off_color;
    setColor(color);
    drawFilledCircle(x, y, size / 2);
    if (label_on) {
        drawLabel(x, y);
    }
}
