// Copyright 2019 Roie R. Black
#include "SevenSeg.h"

const int SEG_WIDTH = 80;
const int SEG_HEIGHT = 90;
const int BAR_HEIGHT = 10;

int hex_digit[16] = {
    0b00111111,     // 0
    0b00000110,     // 1
    0b01011011,     // 2
    0b01001111,     // 3
    0b01100110,     // 4
    0b01101101,     // 5
    0b01111101,     // 6
    0b00000111,     // 7
    0b01111111,     // 8
    0b01100111,     // 9
    0b01110111,     // A
    0b01111100,     // B
    0b00111001,     // C
    0b01011110,     // D
    0b01111001,     // E
    0b01110001      // F
};

// constructor
SevenSeg::SevenSeg() {
    width = SEG_WIDTH;
    height = SEG_HEIGHT;
    bar = BAR_HEIGHT;
    bg_color = GREEN;
    led_on_color = RED;
    led_off_color = bg_color;
    bits = 0b11111111;
}

// mutators
void SevenSeg::set_pos(int xp, int yp) {
    x = xp;
    y = yp;
}

void SevenSeg::set_hex_digit(int n) {
    n = (n % 16);
    set_on(hex_digit[n]);
}

void SevenSeg::set_decimal_digit(int n) {
    n = (n % 10);
    set_on(hex_digit[n]);
}

void SevenSeg::set_bg_color(ColorName color) {
    bg_color = color;
}

void SevenSeg::set_led_on_color(ColorName color) {
    led_on_color = color;
}

void SevenSeg::set_led_off_color(ColorName color) {
    led_off_color = color;
}

void SevenSeg::set_on(int obits) {
    bits = obits;
}

void SevenSeg::set_off(void) {
    bits = 0b00000000;
}

// private utility routines
void SevenSeg::drawFilledSeg(int pos[6][2], int seg, ColorName color) {
    setColor(color);
    int xs1 = pos[0][0];
    int ys1 = pos[0][1];
    int xs2 = pos[1][0];
    int ys2 = pos[1][1];
    int xs3 = pos[2][0];
    int ys3 = pos[2][1];
    int xs4 = pos[3][0];
    int ys4 = pos[3][1];
    int xs5 = pos[4][0];
    int ys5 = pos[4][1];
    int xs6 = pos[5][0];
    int ys6 = pos[5][1];
    glBegin(GL_POLYGON);
    glVertex2i(x + xs1, y + ys1);
    glVertex2i(x + xs2, y + ys2);
    glVertex2i(x + xs3, y + ys3);
    glVertex2i(x + xs4, y + ys4);
    glVertex2i(x + xs5, y + ys5);
    glVertex2i(x + xs6, y + ys6);
    glVertex2i(x + xs1, y + ys1);
    glEnd();
}

void SevenSeg::drawFilledSegA(ColorName color) {
    int left = bar+3;
    int pos[6][2] = {
        {bar / 2, height - bar / 2},
        {bar, height},
        {width - left - bar, height},
        {width - left - bar / 2, height - bar / 2},
        {width - left - bar, height - bar},
        {bar, height - bar}
    };
    drawFilledSeg(pos, 0, color);
}

void SevenSeg::drawFilledSegB(ColorName color) {
    int left = bar + 3;
    int pos[6][2] = {
        {width - left - bar / 2, height - bar / 2},
        {width - left, height - bar},
        {width - left, height / 2 + bar / 2},
        {width - left - bar / 2, height / 2},
        {width - left - bar, height / 2 + bar / 2},
        {width - left - bar, height - bar}
    };
    drawFilledSeg(pos, 1, color);
}

void SevenSeg::drawFilledSegC(ColorName color) {
    int left = bar + 3;
    int pos[6][2] = {
        {width - left - bar / 2, bar / 2},
        {width - left, bar},
        {width - left, height / 2 - bar / 2},
        {width-left - bar / 2, height / 2},
        {width - left - bar, height / 2 - bar / 2},
        {width - left - bar, bar}
    };
    drawFilledSeg(pos, 2, color);
}

void SevenSeg::drawFilledSegD(ColorName color) {
    int left = bar + 3;
    int pos[6][2] = {
        {bar / 2, bar / 2},
        {bar, 0},
        {width - left - bar, 0},
        {width - left - bar / 2, bar / 2},
        {width - left - bar, bar},
        {bar, bar}
    };
    drawFilledSeg(pos, 3, color);
}

void SevenSeg::drawFilledSegE(ColorName color) {
    int left = bar + 3;
    int pos[6][2] = {
        {bar / 2, bar / 2},
        {bar, bar},
        {bar, height / 2 - bar / 2},
        {bar / 2, height / 2},
        {0, height / 2 - bar / 2},
        {0, bar}
    };
    drawFilledSeg(pos, 4, color);
}

void SevenSeg::drawFilledSegF(ColorName color) {
    int left = bar + 3;
    int pos[6][2] = {
        {bar / 2, height / 2},
        {bar, height / 2 + bar / 2},
        {bar, height - bar},
        {bar / 2, height - bar / 2},
        {0, height - bar},
        {0, height / 2 + bar / 2}
    };
    drawFilledSeg(pos, 5, color);
}

void SevenSeg::drawFilledSegG(ColorName color) {
    int left = bar + 3;
    int pos[6][2] = {
        {bar / 2, height / 2},
        {bar, height / 2 - bar / 2},
        {width - left - bar, height / 2 - bar / 2},
        {width - left - bar / 2, height / 2},
        {width - left- bar, height / 2 + bar / 2},
        {bar, height / 2 + bar / 2}
    };
    drawFilledSeg(pos, 6, color);
}

void SevenSeg::drawFilledSegDot(ColorName color) {
    int xd = x + width - bar / 2;
    int yd = y + bar / 2;
    setColor(color);
    drawFilledCircle(xd, yd, bar / 2);
}

void SevenSeg::draw(void) {
    setColor(bg_color);
    drawFilledBox(x, y, x + width, y + height);
    bool ca, cb, cc, cd, ce, cf, cg, cdot;
    ca = (bits & 0b00000001) > 0;
    cb = (bits & 0b00000010) > 0;
    cc = (bits & 0b00000100) > 0;
    cd = (bits & 0b00001000) > 0;
    ce = (bits & 0b00010000) > 0;
    cf = (bits & 0b00100000) > 0;
    cg = (bits & 0b01000000) > 0;
    cdot = (bits & 0b10000000) > 0;

    drawFilledSegA(ca ? led_on_color : led_off_color);
    drawFilledSegB(cb ? led_on_color : led_off_color);
    drawFilledSegC(cc ? led_on_color : led_off_color);
    drawFilledSegD(cd ? led_on_color : led_off_color);
    drawFilledSegE(ce ? led_on_color : led_off_color);
    drawFilledSegF(cf ? led_on_color : bg_color);
    drawFilledSegG(cg ? led_on_color : bg_color);
    drawFilledSegDot(cdot ? led_on_color : led_off_color);
}
