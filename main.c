#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "levenshtein.h"
#include "sine.h"

int main(int argc, char **argv) {


    FILE* fileWriter = fopen("data.txt", "w");
    for (int i = 0; i < argc; i++) {
        fprintf(fileWriter, "%s\n", argv[i]);
    }

    fclose(fileWriter);


    FILE* fileReader = fopen("data.txt", "r");
    char c = fgetc(fileReader);
    while (c != EOF) {
        putchar(c);
        c = fgetc(fileReader);
    }
    fclose(fileReader);

    // char *commands[] = {"echo vscode", "echo chicken"};

    // // char *ref[] = "heaps3d";

    // char* str1 = scanString('\n');

    // int lTotal = levenshteinDistance(str1, str2);

    // free(str2);

    return 0;
}

// int main() {
//     // char *word_list[] = {"apple", "chick", "banana", "grape", "kiwi", "mango", "orange"};
//     char *word_list[] = {"vs heaps3d", "fs heaps3d", "banana", "grape", "mango", "orange"};
//     int list_size = sizeof(word_list) / sizeof(word_list[0]);

//     char input_word[100] = ":C";
//     while (input_word[0] != '!' ) {
//         printf("Enter a word: ");
//         scanf("%s", input_word);

//         char *most_similar = find_most_similar_word(input_word, word_list, list_size);
//         printf("The most similar word is: %s\n", most_similar);

//     }

//     return 0;
// }
// Function to find the most similar word in the list
char *findWord(char *input_word, char *word_list, int list_size) {
    char *most_similar_word = NULL;
    // int min_distance = -1;

    // for (int i = 0; i < list_size; i++) {
    //     int distance = levenshteinDistance(input_word, word_list[i]);
    //     if (min_distance == -1 || distance < min_distance) {
    //         min_distance = distance;
    //         most_similar_word = word_list[i];
    //     }
    // }

    return most_similar_word;
}


