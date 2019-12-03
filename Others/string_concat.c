#include <stdio.h>
#include <stdlib.h>
int stringlen(char *s); // 函数声明

int main()
{
    char* a = (char*) malloc(90 * sizeof(char));
    char* b = (char*) malloc(80 * sizeof(char));
    scanf("%s", a);
    scanf("%s", b);

    //分别计算两字符串长度
    int len_a = stringlen(a);
    int len_b = stringlen(b);

    for (int i = 0; i < 5 || b[i] != '\0'; i++)
    {
        a[len_a++] = b[i];
    }
    
    printf("%s\n", a);
    return 0;
}

// 函数定义
int stringlen(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}