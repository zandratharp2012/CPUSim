// Copyright 2019 Roie R. Black
#include "Button.h"
#include "Graphics.h"
#include <iostream>
#define font GLUT_BITMAP_9_BY_15

// constructor
Button::Button() {
    state = true;
    button_on_color = RED;
    button_off_color = GREEN;
    label_on = true;
    label_color = BLUE;
    label = "ON";
    x = 50;
    y = 50;
    size = 24;
}

// mutators
void Button::set_size(int s) {
    size = s;
}

void Button::set_on_color(ColorName c) {
    button_on_color = c;
}

void Button::set_label_color(ColorName c) {
    label_color = c;
}

void Button::set_label(std::string l ) {
    label = l;
}

void Button::set_off_color(ColorName c) {
    button_off_color = c;
}

void Button::set_pos(int lx, int ly) {
        x = lx;
        y = ly;
}

bool Button::toggle(int mousex, int mousey) {
    std::cout
        << "mouse x: "
        << mousex
        << " y: "
        << mousey << std::endl;
    std::cout
        << "button x: "
        << x
        << " y: "
        << y
        << " size: "
        << size
        << std::endl;
    if (
            (mousex >= x - size && mousex <= x + size/2)
         && (mousey >= y -size && mousey <= y +  size/2))

             state = !state;
    std::cout << state << std::endl;
    return state;
}

void Button:: set_state(bool s) {
    state = s;
}

bool Button::get_state(void) {
    return state;
}

void Button::drawLabel(int x, int y) {
    int j = label.length();
    int vw = (j * 9) / 2;
    int vh = 5;
    setColor(label_color);
    glRasterPos2i(x - vw, y - vh);
    for (int i = 0; i < j; i++) {
        glutBitmapCharacter(font, label[i]);
    }
}

void Button::draw() {
    ColorName color;
    color = state ? button_on_color : button_off_color;
    setColor(color);
    drawFilledCircle(x, y, size / 2);
    if (label_on) {
        drawLabel(x, y);
    }
}
