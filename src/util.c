
#include "util.h"

#include <stdio.h>
#include <stdlib.h>

int minINF(int a, int b) {
    /*
     * a < b
     * inf < inf => true
     */
    if (b == INFINITY) return 1;
    if (a == INFINITY) return 0;
    return a < b;
}

int addINF(int a, int b) {
    /*
     * a + b
     */
    if (a == INFINITY) return INFINITY;
    if (b == INFINITY) return INFINITY;
    return a + b;
}

// Function to calculate the minimum of three numbers
int min3(int a, int b, int c) {
    // returns the smallest number of 3
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int strLen(char *inputString) {
    // calculates the length of a string
    int length = 0;
    while (inputString[length] != '\0') {
        length++;
    }
    return length;
}

/*
 * int size: the memory size to allocate
 * Allocates a block of memory in the heap and returns its pointer
 */
void *safeMalloc(int size) {
    void *p = malloc(size);
    if (p == NULL) {
        printf("could not allocate memory");
        exit(EXIT_FAILURE);
    }
    return p;
}

char *scanString(char endChar) {
    // dynamically scans a string from the io
    int size = 1;
    char *p = (char *)safeMalloc(sizeof(char) * (size + 1));

    char current = getchar();
    int iPosition = 0;

    while (current != endChar) {
        if (size < iPosition) {
            // reallocate more space in memory
            size *= 2;
            p = realloc(p, sizeof(char) * (size + 1));
        }

        p[iPosition] = current;

        current = getchar();

        iPosition++;
    }

    size = iPosition;
    p[iPosition] = '\0';
    return p;
}