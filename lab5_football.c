#include <stdio.h>

#define MAX_COMBINATIONS 50

void findScoringCombinations(int score, int combinations[], int index, int* combinationCount) {
    if (score == 0) {
        if (*combinationCount < MAX_COMBINATIONS) {
            // Print the combination
            printf("Combination %d: ", (*combinationCount) + 1);
            for (int i = 0; i < index; i++) {
                if (i > 0) {
                    printf(" + ");
                }

                if (combinations[i] == 6) {
                    printf("Touchdown (6 points)");
                } else if (combinations[i] == 3) {
                    printf("Field Goal (3 points)");
                } else if (combinations[i] == 2) {
                    printf("Safety (2 points)");
                } else if (combinations[i] == 8) {
                    printf("Touchdown (6 points) + 2-Point Conversion (2 points)");
                } else if (combinations[i] == 7) {
                    printf("Touchdown (6 points) + 1-Point Field Goal (1 point)");
                }
            }
            printf("\n");
            (*combinationCount)++;
        }
        return;
    }

    if (score >= 6) {
        combinations[index] = 6;
        findScoringCombinations(score - 6, combinations, index + 1, combinationCount);
    }

    if (score >= 3) {
        combinations[index] = 3;
        findScoringCombinations(score - 3, combinations, index + 1, combinationCount);
    }

    if (score >= 2) {
        combinations[index] = 2;
        findScoringCombinations(score - 2, combinations, index + 1, combinationCount);
    }

    if (score >= 8) {
        combinations[index] = 8;
        findScoringCombinations(score - 8, combinations, index + 1, combinationCount);
    }

    if (score >= 7) {
        combinations[index] = 7;
        findScoringCombinations(score - 7, combinations, index + 1, combinationCount);
    }
}

int main() {
    int score;
    int combinations[10]; // Assuming a maximum of 10 scoring plays for a single score
    int combinationCount;

    while (1) {
        printf("Enter an NFL score (Enter 0 or a negative value to exit): ");
        scanf("%d", &score);

        if (score <= 0) {
            break;
        }

        if (score < 2) {
            printf("No valid scoring combinations for a score less than 2 points.\n");
        } else {
            printf("Possible scoring combinations for %d points:\n", score);
            combinationCount = 0;
            findScoringCombinations(score, combinations, 0, &combinationCount);

            if (combinationCount == MAX_COMBINATIONS) {
                printf("Maximum combinations limit (50) reached.\n");
            }
        }
    }

    return 0;
}
