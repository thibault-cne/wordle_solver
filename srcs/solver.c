//
// Created by Thibault Cheneviere on 17/03/2022.
//

#include <stdlib.h>

#include "../includes/solver.h"
#include "../includes/coreFunctions.h"
#include "../includes/possibleWords.h"
#include "../includes/analyzeWords.h"

int coreSolver(int const wordLength, int const turnNumber) {
    char firstLetter;
    int const realWordLength = wordLength + 1;

    getFirstLetter(&firstLetter);

    int const possibleWordsNb = countPossibleWords((char) firstLetter, realWordLength);

    char **possibleWords;
    possibleWords = malloc(sizeof(char *) * (possibleWordsNb + 1));

    initPossibleWords((char) firstLetter, realWordLength, (char **) possibleWords);

    analyzeWords(realWordLength, (char **) possibleWords, possibleWordsNb, turnNumber);

    return 1;
}