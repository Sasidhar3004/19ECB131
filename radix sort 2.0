#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
}

// Radix Sort function for positive numbers
void radixSortPositive(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Function to reverse an array
void reverseArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Function to sort an array containing both positive and negative numbers
void radixSortMixed(int arr[], int n) {
    int* positiveArr = (int*)malloc(n * sizeof(int));
    int* negativeArr = (int*)malloc(n * sizeof(int));
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            positiveArr[positiveCount++] = arr[i];
        } else {
            negativeArr[negativeCount++] = abs(arr[i]); // Store absolute values for sorting
        }
    }

    radixSortPositive(positiveArr, positiveCount);
    radixSortPositive(negativeArr, negativeCount);

    reverseArray(negativeArr, negativeCount); // Reverse the negative array

    // Reconstruct the original array
    int index = 0;
    for (int i = 0; i < negativeCount; i++) {
        arr[index++] = -negativeArr[i]; // Restore the negative sign
    }
    for (int i = 0; i < positiveCount; i++) {
        arr[index++] = positiveArr[i];
    }

    free(positiveArr);
    free(negativeArr);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, -75, 90, -802, 24, -2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSortMixed(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
