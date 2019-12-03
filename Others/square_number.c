#include <stdio.h>
#include <math.h>

int isSquareNumber(int num) {
    int root = sqrt( (double) num );
    
    if (root * root == num) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int exist = 0;

    for (int i = m; i <= n; i++)
    {
        // i + 100
        int flag1 = isSquareNumber(i + 100);

        // i + 268
        int flag2 = isSquareNumber(i + 268);

        if (flag1 && flag2)
        {
            exist = 1;
            printf("%d ", i);
        }
    }

    if (!exist)
    {
        printf("no\n");
    }

    return 0;
}