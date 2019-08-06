// Copyright 2019 Roie R. Black
#include <stdio.h>
#include <string>
#include <cstdint>
#include "sim-graphics.h"

ArrowButton arrow_button1;
ArrowButton arrow_button2;
StageBar stage_bar;
HexBar hex_bar;
LEDmatrix led_matrix;
TextBox text_box1;
TextBox text_box2;
Button stop_button;

bool toggle = true;
int digit = 0;
int delta_count = 1;
int64_t frames = 0;
const int FRAME_RATE = 80;
const float DELAY = 1000.0 / FRAME_RATE;

void showTime(void) {
    int time = frames;
    std::string msg = "Cycles: 000000";
    std::snprintf(&msg[8], sizeof(&msg[8]), "%6d", time);
    showString(60, 200, msg);
}

void animate(int t) {   // t is unused here
    frames++;
    int stage = ((frames / (FRAME_RATE / 4)) % 4);
    stage_bar.set_stage(stage);

    if ((frames % FRAME_RATE) == 0) {
        digit = (digit + delta_count) % 65536;
        if (digit < 0) digit = 65535;
    }
    hex_bar.set_value(frames);
    if ((frames % (FRAME_RATE / 8)) ==0) 
        led_matrix.update();
    
    std::string msg = "Frames: 0000";
    std::snprintf(&msg[8], 4, "%4d", frames);
    text_box2.set_text(msg);

    glutPostRedisplay();
    glutTimerFunc(DELAY, animate, 0);
}

void drawScene(void) {
    clearWindow();
    // ------------------------------------------------
    //
    // display stage indicator
    stage_bar.set_pos(40, 300);
    showTime();

    // show mouse position
    showMouse(mousex, mousey);

    // display hex matrix with animation

    led_matrix.set_pos(200, 300);
    led_matrix.draw();

    // hex display tracks machine cycles
    hex_bar.set_pos(40, 80);
    hex_bar.draw();

    // arrow buttons to control sim speed
    arrow_button1.set_size(50);
    arrow_button1.set_pos(500,100);
    arrow_button1.set_direction("up");
    arrow_button1.draw();
    arrow_button2.set_size(50);
    arrow_button2.set_pos(500,50);
    arrow_button2.set_direction("down");
    arrow_button2.draw();

    // mouse control to stop simulation
    stop_button.set_pos(220, 200);
    stop_button.draw();

    text_box1.set_pos(600, 100);
    text_box1.draw();
    text_box2.set_pos(600, 120);
    text_box2.draw();

    // show stage bar
    stage_bar.draw();
    //-----------------------------------------------------
    glEnd();
    glFlush();
    glutSwapBuffers();
}
