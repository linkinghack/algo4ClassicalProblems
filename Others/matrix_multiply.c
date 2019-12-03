#include <stdio.h>

int main() {
    int m,n,p;
    scanf("%d %d %d", &m, &n, &p);
    int m1[10][10] = {0};
    int m2[10][10] = {0};

    // Input matrix 1 (m x n)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    // Input matrix 2 (n x p)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d", &m2[i][j]);
        }
        
    }
    
    // Multiply and output
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int tempPos = 0;
            for (int k = 0; k < n; k++)
            {
                tempPos += m1[i][k] * m2[k][j];
            }
            printf("%d ", tempPos);
        }
        putchar('\n');
    }
    
    return 0;
}