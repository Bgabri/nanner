#include <stdio.h>
#include <stdlib.h>
#include "levenshtein.h"
#include "util.h"
#include "data.h"


// void geEntry
char *readLine(FILE* fileReader, char endChar) {
    // dynamically scans a string from the file stream
    int size = 1;
    char *p = (char*) safeMalloc(sizeof(char) * (size + 1));


    char current = fgetc(fileReader);
    int iPosition = 0;

    while (current != endChar && current != EOF) {
        if (size <= iPosition) {
            // reallocate more space in memory
            size *= 2;
            p = realloc(p, sizeof(char) * (size + 1));

        }

        p[iPosition] = current;

        current = fgetc(fileReader);

        iPosition++;
    } 

    size = iPosition;
    p[iPosition] = '\0';
    return p;
}

char* getFuzzyEntry(char *alias) {
    
    char *minEntry = NULL;
    int minDistance = INFINITY;
    FILE* fileReader = fopen(DATA_PATH, "r");

    char *currentAlias = readLine(fileReader, '\n');
    while (currentAlias[0] != '\0') {

        char *cmd = readLine(fileReader, '\n');
        int distance = levenshteinDistance(alias, currentAlias);

        if (minINF(distance, minDistance)) {
            free(minEntry);
            minEntry = cmd;
            minDistance = distance;
        } else {
            free(cmd);
        }


        free(currentAlias);
        currentAlias = readLine(fileReader, '\n');
    }

    free(currentAlias);
    fclose(fileReader);


    return minEntry;

}


void setEntry(char *alias, char *command) {
    printError("set entry function not implemented", 0);

}



void addEntry(char *alias, char *command) {

    FILE* fileWriter = fopen(DATA_PATH, "a");

    fprintf(fileWriter, "%s\n", alias);
    fprintf(fileWriter, "%s\n", command);
    fclose(fileWriter);
}

void removeEntry(char *alias, char *command) {
    printError("remove entry function not implemented", 0);
}
