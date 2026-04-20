#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int x[30]; // Array to store column positions for each row (1-indexed)
int solution_count = 0;
// The "place" function based on your logic: Checks if row k, column i is safe
bool place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        // x[j] == i checks for same column
        // abs(x[j] - i) == abs(j - k) checks for diagonals
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return false;
        }
    }
    return true;
}
// Function to print both the set and the visual board
void printSolution(int n) {
    solution_count++;

    // 1. Print the Solution Set
    printf("Solution %d: Set = [", solution_count);
    for (int i = 1; i <= n; i++) {
        printf("%d%s", x[i], (i == n ? "" : ", "));
    }
    printf("]\n");
    // 2. Print the Visual Chessboard
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                printf(" Q "); // Queen at this column
            else
                printf(" - "); // Empty square
        }
        printf("\n");
    }
    printf("*********************\n\n");
}
// The "nqueens" recursive function
void nqueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                // If all queens are placed, print the result
                printSolution(n);
            } else {
                // Move to next row
                nqueens(k + 1, n);
            }
        }
    }
}
int main() {
    int n;
    printf("Enter chess board size n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid board size.\n");
        return 1;
    }
    nqueens(1, n);
    if (solution_count == 0) {
        printf("No solutions exist for size %d.\n", n);
    } else {
        printf("Total solutions found: %d\n", solution_count);
    }
    return 0;
}

