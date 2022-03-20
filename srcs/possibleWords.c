//
// Created by Thibault Cheneviere on 18/03/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../includes/possibleWords.h"
#include "../includes/coreFunctions.h"

int countPossibleWords(char firstLetter, int wordLength) {
    int possibleWordNb = 0;

    const char *filename = "/Users/thibault/Documents/TN/Cours/PPII/Semestre-2/TelecomWORDLE/data/txt/dictionary.txt";
    FILE *file = fopen(filename, "r");

    if(file == NULL){
        perror("\n Unable to open : dictionary.txt");
        return 0;
    }

    char line[wordLength];

    int lineSize = 500;

    while (fgets(line, lineSize, file)) {
        unsigned long tempLength = strlen(line);
        int tempLineLength = (int) tempLength;

        if (line[0] == firstLetter && tempLineLength == wordLength) {
            possibleWordNb ++;
        }
    }
    fclose(file);

    return possibleWordNb;
}


int initPossibleWords(char firstLetter, int wordLength, char **wordsArray) {
    const char *filename = "/Users/thibault/Documents/TN/Cours/PPII/Semestre-2/TelecomWORDLE/data/txt/dictionary.txt";
    FILE *file = fopen(filename, "r");

    if(file == NULL){
        perror("\n Unable to open : dictionary.txt");
        return 0;
    }

    char line[wordLength];

    int lineSize = 500;
    int wordIndex = 0;

    while (fgets(line, lineSize, file)) {
        unsigned long tempLength = strlen(line);
        int tempLineLength = (int) tempLength;

        if (line[0] == firstLetter && tempLineLength == wordLength) {
            wordsArray[wordIndex] = malloc(sizeof(char) * (wordLength));
            strcpy(wordsArray[wordIndex], line);
            wordIndex ++;
        }
    }
    fclose(file);

    return 1;
}