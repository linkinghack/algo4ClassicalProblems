#include<stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int tempN = n;
    int sum = 0;

    while (tempN > 0) {
        int digit = tempN % 10;
        sum += digit;
        tempN /= 10;
    }

    if (n % sum == 0) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    
    return 0;
}