// Copyright 2019 Roie R. Black
#include <string>
#include "sim-graphics.h"
#include "TextBox.h"

TextBox::TextBox() {
    x = 100;
    y = 100;
    width = 12; // in characters
    height = 20;
    text = "Hello, World!";
}

void TextBox::draw(void) {
    showString(x, y, text);
    drawBox(x,y,x + width * 9, y + height);
}

void TextBox::set_text(std::string msg) {
    text = msg;
}

void TextBox::set_pos(int lx, int ly) {
    x = lx;
    y = ly;
}

