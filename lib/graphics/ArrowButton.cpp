// Copyright 2019 Roie R. Black
#include "ArrowButton.h"
#include "Graphics.h"
#include <iostream>
#define font GLUT_BITMAP_9_BY_15

// constructor
ArrowButton::ArrowButton() {
    state = true;
    button_on_color = RED;
    button_off_color = GREEN;
    label_on = true;
    label_color = BLUE;
    label = "ON";
    x = 250;
    y = 50;
    size = 25;
    border = 5;
    direction = RIGHT;
}

// mutators
void ArrowButton::set_size(int s) {
    size = s;
}

void ArrowButton::set_direction(std::string dir) {
    if (dir == "up")  direction = UP; 
    else if (dir == "down") direction = DOWN;
    else if (dir == "left") direction = LEFT;
    else if (dir == "right") direction = RIGHT;
    else {
        std::cout << "ignoring bad direction" << std::endl;
    }
}

void ArrowButton::set_on_color(ColorName c) {
    button_on_color = c;
}

void ArrowButton::set_label_color(ColorName c) {
    label_color = c;
}

void ArrowButton::set_label(std::string l ) {
    label = l;
}

void ArrowButton::set_off_color(ColorName c) {
    button_off_color = c;
}

void ArrowButton::set_pos(int lx, int ly) {
        x = lx;
        y = ly;
}

void ArrowButton::toggle(int mousex, int mousey) {
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
            (mousex >= x && mousex <= x + size)
         && (mousey >= y && mousey <= y +  size))

             state = !state;
    std::cout << state << std::endl;
}

void ArrowButton:: set_state(bool s) {
    state = s;
}

bool ArrowButton::get_state(void) {
    return state;
}

void ArrowButton::drawLabel(int x, int y) {
    int j = label.length();
    int vw = (j * 9) / 2;
    int vh = 5;
    setColor(label_color);
    glRasterPos2i(x + size/2 - vw, y + size/2  - vh);
    for (int i = 0; i < j; i++) {
        glutBitmapCharacter(font, label[i]);
    }
}

void ArrowButton::draw() {
    ColorName color;
    color = state ? button_on_color : button_off_color;
    setColor(GREEN);
    drawFilledBox(x, y, x + size, y + size);
    setColor(color);
    drawArrow();
    setColor(BLACK);
    drawBox(x, y, x + size, y + size);
    if (label_on) {
        drawLabel(x, y);
    }
}

void ArrowButton::drawArrow(void) {
    switch (direction) {
        case UP:
            drawFilledTriangle(
                x + border, y + border, 
                x + size - border, y +  border, 
                x + size/2, y + size - border);
            break;
        case DOWN:
            drawFilledTriangle(
                x + border, y + size - border, 
                x + size - border, y +  size - border, 
                x + size/2, y +  border);
            break;
        case RIGHT:
            drawFilledTriangle(
                x + border, y + border, 
                x + size - border, y +  size/2, 
                x + border, y + size - border);
            break;
        case LEFT:
            drawFilledTriangle(
                x + border, y + size/2, 
                x + size - border, y +  size/2, 
                x + border, y + size - border);
            break;
        default:
            std::cout << "Illegal direction value - ignoring" << std::endl;
    }
}


