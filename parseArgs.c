
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "parseArgs.h"
#include "data.h"
/*
 * nnr set alias command
 * nnr get fuz
 * nnr list fuz
 * nnr remove
 * nnr help
 * 
 * switches:
 *  -d, --dry
 *      fuzzy cmd find without execution
 *  -f, --force
 *      do not prompt
 *  -i, --interactive
 *      prompt before executing cmd
 *  -q, --quiet
 *      recklessly execute matched cmd
 *  -p, --perfect
 *      dont fuzzy match
 */


int parseInput(char *argv[]) {
    if (*argv == NULL) return 0;

    if (argv[0][0] == '-') return parseSwitch(argv);
    
    if (!strcmp(argv[0], SET))    return parseSet(&argv[1]);
    if (!strcmp(argv[0], GET))    return parseGet(&argv[1]);
    if (!strcmp(argv[0], LIST))   return parseList(&argv[1]);
    if (!strcmp(argv[0], REMOVE)) return parseRemove(&argv[1]);
    if (!strcmp(argv[0], HELP))   return parseRemove(&argv[1]);

    char* cmd = getFuzzyEntry(argv[0]);
    system(cmd);
    free(cmd);

    return 1;
}

int parseSet(char *argv[]) {
    if (*argv == NULL) return 0;
    printError("parse set function not implemented", 0);
    return 1;
}


int parseGet(char *argv[]) {
    if (*argv == NULL) return 0;
    printError("parse get function not implemented", 0);
    return 1;
}


int parseList(char *argv[]) {
    listEntries();
    parseInput(&argv[0]);
    return 1;
}

int parseRemove(char *argv[]) {
    if (*argv == NULL) return 0;
    printError("parse remove function not implemented", 0);
    return 1;
}

int parseHelp(char *argv[]) {
    if (*argv == NULL) return 0;
    printError("parse help function not implemented", 0);
    return 1;
}

int parseSwitch(char *argv[]) {
    if (*argv == NULL) return 0;
    printError("parse switch function not implemented", 0);
    
    return 1;

}