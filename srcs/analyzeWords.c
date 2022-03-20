//
// Created by Thibault Cheneviere on 19/03/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../includes/analyzeWords.h"
#include "../includes/coreFunctions.h"

int analyzeWords(int const wordLength, char **possibleWords, int const wordNumber, int const turnNumber) {
    int bestRate = 0;
    char *bestWord;
    bestWord = malloc(sizeof(char) * wordLength);

    for (int index = 0; index < wordNumber; index++) {
        int tempRate = rateWord(possibleWords[index]);

        if (tempRate > bestRate) {
            bestRate = tempRate;
            strcpy(bestWord, possibleWords[index]);
        }
    }

    printf("%s", "Voici le meilleur choix possible : ");
    printf("%s\n", bestWord);

    int **analysisResult;
    analysisResult = malloc(sizeof(int *) * (turnNumber + 1));

    int endStatement = 1;

    for (int i = 0; i < turnNumber; i++) {
        analysisResult[i] = malloc(sizeof(int) * wordLength);
        storeResult(bestWord, analysisResult[i], wordLength);

        analyzeTurnWords(possibleWords, analysisResult[i], bestWord, wordLength, wordNumber);
    }

    return 0;
}

void analyzeTurnWords(char **possibleWords, const int *analysisResult, char *previousWord, int const wordLength, int wordNb) {
    int bestWordScore = 0;
    int tempWordScore;

    char *tempBestWord;
    tempBestWord = malloc(sizeof(char) * wordLength);

    removeUnusedWords(possibleWords, analysisResult, previousWord, wordLength, wordNb);

    for (int i = 0; i < wordNb; i ++) {
        if (possibleWords[i][0] != '\0') {
            tempWordScore = rateWord(possibleWords[i]);

            if (tempWordScore > bestWordScore) {
                strcpy(tempBestWord, possibleWords[i]);
                bestWordScore = tempWordScore;
            }
        }
    }


    printf("%s", "Voici la meilleur option : ");
    printf("%s\n", tempBestWord);

    // We put the new tempBestWord value in the previousWord value to continue the loop
    strcpy(previousWord, tempBestWord);
}

int storeResult(char *word, int *result, int const wordLength) {
    char tempResult[wordLength];
    int endStatement = 1;

    for (int i = 1; i < wordLength - 1; i++) {
        printf("%s", "Résultat du mot entré (B, J, R) pour la lettre ");
        printf("%c", word[i]);
        printf("%s", ": ");
        scanf("%s", &tempResult[i]);

        if (tempResult[i] == 'B') {
            result[i] = 0;
            endStatement = 0;
        } else if (tempResult[i] == 'J') {
            result[i] = 1;
            endStatement = 0;
        } else if (tempResult[i] == 'R'){
            result[i] = 2;
        }
    }

    if (endStatement == 1) {
        printf("%s\n", "C'est gagné !");
        exit(1);
    }

    return 1;
}

int removeUnusedWords(char **possibleWords, const int *analysisResult, char *previousWord, int const wordLength, int const wordNb) {
    for (int i = 0; i < wordNb; i++) {
        if (strcmp(possibleWords[i], "") != 0) {
            int tempWordValidation = 1;
            int j;
            j = 0;

            while (possibleWords[i][++j] && j < wordLength - 1) {
                switch (analysisResult[j]) {
                    case 2:
                        if (possibleWords[i][j] != previousWord[j]) {
                            tempWordValidation = 0;
                        }
                        break;
                    case 1:
                        if (possibleWords[i][j] == previousWord[j]) {
                            tempWordValidation = 0;
                        }
                        if (countLetterOccurency(possibleWords[i], previousWord[j]) == 0) {
                            tempWordValidation = 0;
                        }
                        break;
                    case 0:
                        if (countLetterOccurency(possibleWords[i], previousWord[j]) > 0) {
                            tempWordValidation = 0;
                        }
                        break;
                    default:
                        break;
                }
            }

            if (strcmp(possibleWords[i], previousWord) == 0) {
                tempWordValidation = 0;
            }

            if (tempWordValidation == 0) {
                strcpy(possibleWords[i], "");
            }
        }
    }

    return 1;
}