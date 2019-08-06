#include <math.h>
#include <GL/glut.h>
#include "Graphics.h"
#include "LED.h"
#include "SevenSeg.h"
#include "LEDbar.h"
#include "Button.h"
#include "mouse.h"
#include "LEDmatrix.h"
#include "machine.h"
#include "hexdisplay.h"
#include "keyboard.h"
#include "arg_parse.h"
#include "gui.h"
#include "version.h"

extern bool debug;
extern bool enablegui;
extern int simsteps;

int main(int argc, char * argv[]) {
    const int FRAME_RATE = 80;
    const float DELAY = 1000.0 / FRAME_RATE;
    std::cout << "avrsim (v" << VERSION << ")" << std::endl;
    arg_parse(argc, argv);
    if (debug)
        std::cout << "(debugging enabled)" << std::endl;
    if (enablegui) {
        graphicsSetup(argc, argv);
        glutDisplayFunc(drawScene);
        glutKeyboardFunc(handleKey);    // set up the "q" key to quit
        glutMouseFunc(mouse);
        glutTimerFunc(DELAY, animate, 0);
        glutMainLoop();
    }
}
