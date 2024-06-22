#include <stdio.h>

int main()
{
    int num, nthBit, newNum;

    printf("Enter a number:");
    scanf("%d", &num);

    printf("Enter nth bit to toggle (between 0 and 31)");

    while(1) {
      scanf("%d", &nthBit);

      if (nthBit >= 0 && nthBit <= 31)
        break;
      else
        printf("Invalid number, must be in a range 0 - 31.\n");
    }

    
    newNum = num ^ ( 1 << nthBit );
    printf( "The number %d after toggle bit at position %d -> %d.",
      num, nthBit, newNum );

    return 0;
}