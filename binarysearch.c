#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at the middle
        if (arr[mid] == target)
            return mid;

        // If the target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If the target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If the element is not present in the array
    return -1;
}

int main() {
    int n, target;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        printf("Element is not present in the array.\n");
    else
        printf("Element is present at index %d.\n", result);

    return 0;
}
