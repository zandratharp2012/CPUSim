#include <iostream>
#include "arg_parse.h"

void usage() {
    std::cout << "Usage: "
    << "avrsim [-d] [-g ] [-s steps]"
    << std::endl;
    exit(1);
}

void arg_parse(int argc, char *argv[]) {
    // process input parameters
    int i = 1;
    while (true) {
        if (i >= argc) break;
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'g' : enablegui = true; break;
                case 's' : simsteps = std::stoi(argv[++i]); break;
                case 'd' : debug = true; break;
                default : usage();
            }
        } else {
            usage();
        }
        i++;    // look for next arg
    }
}
