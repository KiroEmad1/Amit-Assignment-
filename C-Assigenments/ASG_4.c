#include <stdio.h>

// Function declaration
void edit(int *x);

// Function definition
void edit(int *x) {
	// Increment the value of x by 1
	(*x)++;
}
int main() {
	int x;

	//  user enter a value for x
	printf("Enter the value of x: ");
	scanf("%d", &x);

	// Print the value of x before calling the edit function
	printf("Before calling edit function: x = %d\n", x);

	// Pass the address of x to the edit function
	edit(&x);

	// Print the value of x after calling the edit function
	printf("After calling edit function: x = %d\n", x);

	return 0;
}


