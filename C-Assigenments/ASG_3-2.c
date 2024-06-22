#include <stdio.h>

// Recursive function to calculate Fibonacci number
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

int main() {
    int n;

    // Input from the user
    printf("Enter the value of n for Fibonacci sequence: ");
    scanf("%d", &n);

    // Display the Fibonacci sequence using recursion
    printf("Fibonacci sequence (recursive): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacciRecursive(i));
    }

    return 0;
}

/*#include <stdio.h>

// Iterative function to calculate Fibonacci sequence
void fibonacciIterative(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci sequence (iterative): ");

    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
}

int main() {
    int n;

    // Input from the user
    printf("Enter the value of n for Fibonacci sequence: ");
    scanf("%d", &n);

    // Display the Fibonacci sequence using iteration
    fibonacciIterative(n);

    return 0;
}*/