#include <stdio.h>

int main() {
    int arr_1[5];
    int i;
    int max;
    int min;
    int max_pos;
    int min_pos;
    // Input 
    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr_1[i]);
    }

    //  printing the elements of arr_1
    printf("\nThe elements of arr_1 are: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr_1[i]);
    }

    // Finding maximum and minimum elements and their positions
    max = min = arr_1[0];
    max_pos = min_pos = 0;
    for (i = 1; i < 5; i++) {
        if (arr_1[i] > max) {
            max = arr_1[i];
            max_pos = i;
        }
        if (arr_1[i] < min) {
            min = arr_1[i];
            min_pos = i;
        }
    }
    printf("\n\nMaximum number in arr_1 is %d at position %d.\n", max, max_pos + 1);
    printf("Minimum number in arr_1 is %d at position %d.\n", min, min_pos + 1);

    // Sorting the elements of array in ascending order
    int temp;
    for (i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (arr_1[j] > arr_1[j + 1]) {
                temp = arr_1[j];
                arr_1[j] = arr_1[j + 1];
                arr_1[j + 1] = temp;
            }
        }
    }

    // Printing sorted array
    printf("\nSorted elements of array in ascending order:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr_1[i]);
    }

    return 0;
}

