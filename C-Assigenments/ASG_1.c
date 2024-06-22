#include <stdio.h>

int main(void)
{
    int x;
printf("enter a number");
scanf("%d",&x);
float result = x / 2.0;
if ((x >> 1) == (result)) {
        printf("the number is odd =0\n");
        printf("the number is even =1");
    } else {
         printf("the number is odd =1\n");
        printf("the number is even =0");
    }

    return 0;
}

