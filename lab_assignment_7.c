// Logan Boyd
#include <stdio.h>

// Function to swap two integers
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n, int swaps[], int *total_swaps) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swaps[arr[j+1]]++;  // Increment swap count for both elements
                (*total_swaps)++;
            }
        }
    }
}

// Function to sort an array using selection sort
void selectionSort(int arr[], int n, int swaps[], int *total_swaps) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        if(min_idx != i){
            swap(&arr[min_idx], &arr[i]);
            swaps[arr[i]]++;  // Increment swap count for both elements
            (*total_swaps)++;
        }
    }
}
 
int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72}; // Array to be sorted
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10}; // Array to be sorted
    int n1 = sizeof(array1)/sizeof(array1[0]); // Size of array
    int n2 = sizeof(array2)/sizeof(array2[0]); // Size of array
    int swaps1[100] = {0};  // Assuming values are less than 100 for simplicity
    int swaps2[100] = {0}; 
    int total_swaps1 = 0, total_swaps2 = 0;

    bubbleSort(array1, n1, swaps1, &total_swaps1);
    selectionSort(array2, n2, swaps2, &total_swaps2);

    // Print sorted array
    printf("Array 1 Bubble Sort Swaps:\n");
    // Print number of swaps for each element
    for(int i = 0; i < n1; i++) {
        printf("%d: %d times\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total # of swaps: %d\n\n", total_swaps1);

    printf("Array 2 Selection Sort Swaps:\n");
    for(int i = 0; i < n2; i++) {
        printf("%d: %d times\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total # of swaps: %d\n", total_swaps2);

    return 0;
}
