#include <stdio.h>

int main() {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" "); // 打印i个空格
        }
        
        printf("****\n"); // 打印4个星号然后换行
    }

    return 0;
}