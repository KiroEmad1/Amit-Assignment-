#include <stdio.h>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int isArmstrong(int num) {
    int originalNum, remainder, result = 0, n;

    originalNum = num;
    n = countDigits(num);

    while (originalNum != 0) {
        remainder = originalNum % 10;

       
        int temp = 1;
        for (int i = 0; i < n; i++) {
            temp *= remainder;
        }

        result += temp;
        originalNum /= 10;
    }

    return (result == num);
}

int main() {
    int number;

  
    printf("Enter a number: ");
    scanf("%d", &number);

    
    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
