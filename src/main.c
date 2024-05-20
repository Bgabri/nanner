#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "parseArgs.h"
#include "data.h"



int main(int argc, char **argv) {




    char mgh[123] = {0};

    for(int i = 0; i < 123; i++) {
        printf("%c", mgh[i]);
    }

    parseInput(&argv[1]);

    return 0;
}
