#include <stdio.h>
#include <stdlib.h>
#include "error.h"



char* getColour(colour col) {
    switch (col) {
        case magenta:
            return ANSI_COLOR_MAGENTA;
        case red:
            return ANSI_COLOR_RED;
        case yellow:
            return ANSI_COLOR_YELLOW;
        case green:
            return ANSI_COLOR_GREEN;
        case cyan:
            return ANSI_COLOR_CYAN;
        case blue:
            return ANSI_COLOR_BLUE;
    }
    return "";

}

int printError(char msg[], int priority) {
    
    printf("%s%s%s\n", getColour(priority), msg, ANSI_COLOR_RESET);

    exit(1);
}