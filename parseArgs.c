
#include <stdio.h>
#include <stdlib.h>
/*
 * Grammer
 * <options>    ::= {<option>}
 * <option>     ::= '-'['-']<opcode> ' ' <operand>
 * <operand>    ::= <identifier>
 * <opcode>     ::= <identifier>
 * <identifier> ::= letter {letter}
 */

// -list
// -a man dog
// --help
// -r man
int parseInput(char *argv[]) {
    if (*argv == NULL) return 0;;
    return 1;
    return 0; 
}


int parseAdd(char *argv[]) {
    if (*argv == NULL) return 0;;
    return 1;
}

int parseRemove(char *argv[]) {
    if (*argv == NULL) return 0;;
    return 1;
}

int parseHelp(char *argv[]) {
    if (*argv == NULL) return 0;;
    return 1;
}


int parseOption(char *argv[]) {
    if (*argv == NULL) return 0;;
    
    return 1;

}