//
// Created by Thibault Cheneviere on 17/03/2022.
//

#include <string.h>
#include <stdio.h>

#include "../includes/coreFunctions.h"

int rateWord(char *word) {
    int wordScore = 0;
    unsigned long wordLen = strlen(word);
    int wordLength = (int)wordLen;

    for (int i = 0; i < wordLength; i++) {
        wordScore += wordLength - countLetterOccurency(word, word[i]);
        wordScore += checkVowel(word[i]) * 5;
        wordScore += checkTopLetters(word[i], word, wordLength);
    }

    return wordScore;
}

int countLetterOccurency(const char *word, char letter) {
    int occurency = 0;
    int index;
    index = -1;

    while (word[++index]) {
        if (word[index] == letter) {
            occurency += 1;
        }
    }

    return occurency;
}

int checkVowel(char letter) {
    char vowel[] = "aeiouy";
    int vowelNb = 6;
    int returnStatement = 0;

    for (int i = 0; i < vowelNb; i++) {
        if (vowel[i] == letter) {
            returnStatement = 1;
        }
    }

    return returnStatement;
}

int checkTopLetters(char letter, char *word, int wordLength) {
    char topLetters[] = "eaisnrtolu";
    int topLettersNb = 6;
    int topLetterScore = 0;

    for (int i = 0; i < topLettersNb; i++) {
        if (topLetters[i] == letter) {
            topLetterScore += (10 - i) * (wordLength - countLetterOccurency(word, letter));
        }
    }

    return topLetterScore;
}

int getFirstLetter(char *arg) {
    printf("%s", "Merci de rentrer la première lettre du mot : ");
    scanf("%c", arg);
    return 1;
}