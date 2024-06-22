#include <stdio.h>

void swap(int *x, int *y) {
    printf("Before swapping: x = %d, y = %d\n", *x, *y);

    int temp = *x;
    *x = *y;
    *y = temp;

    printf("After swapping: x = %d, y = %d\n", *x, *y);
}

int main() {
    int num1, num2;

    
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    
    swap(&num1, &num2);

    return 0;
}