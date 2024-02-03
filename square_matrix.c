#include <stdio.h>

#define SIZE 4 // Change the size of the matrix here

void fillMatrix(int mat[][SIZE]) {
    int i, j;

    // Filling the matrix with appropriate values
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == j) {
                // Diagonal elements
                mat[i][j] = 0;
            } else if (i < j) {
                // Upper right triangle
                mat[i][j] = 1;
            } else {
                // Lower left triangle
                mat[i][j] = -1;
            }
        }
    }
}

void displayMatrix(int mat[][SIZE]) {
    int i, j;

    // Displaying the matrix
    printf("Generated Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE];

    // Filling the matrix
    fillMatrix(matrix);

    // Displaying the matrix
    displayMatrix(matrix);

    return 0;
}
