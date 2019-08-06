// Copyright 2019 Roie R. Black
#include "Graphics.h"
#include "keyboard.h"

void handleKey(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
            exit(0);
            break;
        case 't':
            break;
        default:
            break;
    }
}
