// Copyright 2019 Roie R. Black
#include "LEDmatrix.h"
#include "LED.h"
#include "LEDbar.h"
extern int FRAME_RATE;

LEDmatrix::LEDmatrix() {
    x = 100;
    y = 100;
    bg_color = GREEN;
    led_on_color = RED;
    led_off_color = GREEN;
}

void LEDmatrix::set_pos(int lx, int ly) {
    x = lx;
    y = ly;
    bar1.set_pos(x, y);
    bar2.set_pos(x + 20, y);
    bar3.set_pos(x + 40, y);
    bar4.set_pos(x + 60, y);
    bar5.set_pos(x + 80, y);
    bar6.set_pos(x + 100, y);
    bar7.set_pos(x + 120, y);
    bar8.set_pos(x + 140, y);
}

void LEDmatrix::draw(void) {
    bar1.draw();
    bar2.draw();
    bar3.draw();
    bar4.draw();
    bar5.draw();
    bar6.draw();
    bar7.draw();
    bar8.draw();
    setColor(BLACK);
    drawBox(x,y, x+160, y+160);
}

void LEDmatrix::update(void) {
    // play with LEDbar
    int bits = bar1.get_bits();
    bits = ((bits * 2) % 256);
    if (bits ==0) bits = 3;
    bar1.set_on(bits);
    bar2.set_on(bits);
    bar3.set_on(bits);
    bar4.set_on(bits);
    bar5.set_on(bits);
    bar6.set_on(bits);
    bar7.set_on(bits);
    bar8.set_on(bits);
}
