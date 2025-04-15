#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Bucket Sort function
void bucketSort(int arr[], int n) {
    if (n == 0) return;

    // 1. Create buckets
    int num_buckets = n; // You can adjust the number of buckets
    int** buckets = (int**)malloc(sizeof(int*) * num_buckets);
    int* bucket_counts = (int*)malloc(sizeof(int) * num_buckets);

    if (!buckets || !bucket_counts) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
        bucket_counts[i] = 0;
    }

    // 2. Distribute elements into buckets
    int max_val = getMax(arr, n);
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)(((float)arr[i] / (max_val + 1)) * (num_buckets - 1));
        buckets[bucket_index] = (int*)realloc(buckets[bucket_index], sizeof(int) * (bucket_counts[bucket_index] + 1));
        if (!buckets[bucket_index]) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
        buckets[bucket_index][bucket_counts[bucket_index]] = arr[i];
        bucket_counts[bucket_index]++;
    }

    // 3. Sort elements within each bucket (using Insertion Sort here for simplicity)
    for (int i = 0; i < num_buckets; i++) {
        if (bucket_counts[i] > 0) {
            for (int j = 1; j < bucket_counts[i]; j++) {
                int key = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > key) {
                    buckets[i][k + 1] = buckets[i][k];
                    k--;
                }
                buckets[i][k + 1] = key;
            }
        }
    }

    // 4. Concatenate the sorted buckets
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_counts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucket_counts);
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Convert to a suitable integer range for this basic implementation
    int int_arr[n];
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        int_arr[i] = (int
