#include <stdio.h>

#define ROWS 5
#define COLS 3

// Function to find the highest marks in each subject
void highestMarks(int marks[][COLS]) {
    int i, j;
    int maxSubject[COLS];

    // Initialize maxSubject array to minimum possible marks
    for (i = 0; i < COLS; i++) {
        maxSubject[i] = -1; // Assuming marks are non-negative
    }

    // Find the highest marks in each subject
    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            if (marks[j][i] > maxSubject[i]) {
                maxSubject[i] = marks[j][i];
            }
        }
    }

    // Display the highest marks in each subject
    for (i = 0; i < COLS; i++) {
        printf("Highest marks in Subject %d: %d\n", i + 1, maxSubject[i]);
    }
}

int main() {
    int marks[ROWS][COLS];
    int i, j;

    printf("Enter marks of 5 students in 3 subjects:\n");

    // Reading marks from the user
    for (i = 0; i < ROWS; i++) {
        printf("Enter marks for Student %d: ", i + 1);
        for (j = 0; j < COLS; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    // Display the highest marks in each subject
    highestMarks(marks);

    return 0;
}
