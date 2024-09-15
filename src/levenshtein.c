
#include "levenshtein.h"

#include "util.h"

// Function to calculate Levenshtein distance between two strs
int levenshteinDistance(char *str1, char *str2) {
    int len1 = strLen(str1);
    int len2 = strLen(str2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = 1 + min3(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
        }
    }

    return matrix[len1][len2];
}