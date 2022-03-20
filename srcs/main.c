#include "../includes/solver.h"

int main(int argc, char **argv) {
    (void) argc;
    (void) argv;

    int const wordLength = 5;
    int const turnNumber = 5;

    coreSolver(wordLength, turnNumber);

    return 0;
}
