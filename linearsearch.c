#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the target element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int n, target;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target);

    if (result == -1)
        printf("Element is not present in the array.\n");
    else
        printf("Element is present at index %d.\n", result);

    return 0;
}
