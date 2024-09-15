#include "sine.h"

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int convert(char* str1, char* str2, int pos1, int pos2) {
    /* finds the number of steps to convert one string to another
     * where at each recursive step the string is shortened
     */

    // remove remaining characters
    if (str1[pos1] == '\0') return strLen(str2) - pos2;
    if (str2[pos2] == '\0') return strLen(str1) - pos1;

    if (str1[pos1] == str2[pos2]) {  // first charter is the same
        return convert(str1, str2, pos1 + 1, pos2 + 1);
    }

    int insert = convert(str1, str2, pos1, pos2 + 1);
    int delete = convert(str1, str2, pos1 + 1, pos2);
    int replace = 1 + convert(str1, str2, pos1 + 1, pos2 + 1);

    return 1 + min3(insert, delete, replace);
}

int sineDistance(char* str1, char* str2) {
    return convert(str1, str2, 0, 0);
}