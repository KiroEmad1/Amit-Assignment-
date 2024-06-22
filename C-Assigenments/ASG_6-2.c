#include <stdio.h>

// Define a struct for complex numbers
struct Complex {
    float real;
    float imag;
};

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

int main() {
    struct Complex num1, num2, result;

    // Input first complex number
    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    // Input second complex number
    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    // Add the two complex numbers
    result = addComplex(num1, num2);

    // Display the result
    printf("Sum = %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}

