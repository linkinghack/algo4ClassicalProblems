#include<stdio.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    int zero_ends = 0;

    while(num > 0) {
        int digit = num % 10;
        if (digit != 0)
        {
            zero_ends = 1;
        }

        if (zero_ends)
        {
            printf("%d", digit);
        }
        
        num /= 10;
    }

    putchar('\n');
    return 0;
}