// Copyright 2019 Roie R. Black
#include <string>
#include "Graphics.h"
#include "Button.h"
#include "mouse.h"

int mousex, mousey;

void showMouse(int x, int y) {
    int time = frames;
    std::string msg = "Mouse:          ";
        snprintf(&msg[8], sizeof(&msg[8]), "%4d %4d", x, y);
        showString(60, 350, msg);
}

void mouse(int button, int state, int x, int y) {
    y = WINDOW_HEIGHT - y;
    mousex = x;
    mousey = y;

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_UP) {
            // check all buttons to see if any need attention
            if (stop_button.toggle(x, y)) exit(0);
            arrow_button1.toggle(x, y);
            arrow_button2.toggle(x, y);
            delta_count = -delta_count;
        }
    }
}
