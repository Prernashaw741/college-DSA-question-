#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to transpose a 3x3 matrix
void transposeMatrix(int mat[][COLS]) {
    int i, j;
    int transposedMat[COLS][ROWS];

    // Transpose the matrix
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            transposedMat[j][i] = mat[i][j];
        }
    }

    // Display the transposed matrix
    printf("Transposed Matrix:\n");
    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            printf("%d\t", transposedMat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS];
    int i, j;

    printf("Enter elements of a 3x3 matrix:\n");

    // Reading elements of the matrix from the user
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original Matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    transposeMatrix(matrix);

    return 0;
}
