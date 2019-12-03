#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char num1[200] = {'\0'}; // 使用字符串的方式保存大数
    char num2[200] = {'\0'};
    scanf("%s%s", num1, num2);  // 获取用户输入

    // 计算两数长度, 使用了 string.h 提供的 strlen() 函数
    int num1_len = strlen(num1);
    int num2_len = strlen(num2);
    int result_len = num1_len + num2_len;

    // 分配一块足够大的内存来保存乘法结果(两数相乘，结果位数最大不超过两数位数之和))
    //  malloc() 是stdlib.h 提供的动态内存分配工具。这里可以理解为 product是一个字符数组
    //   参考： http://www.cplusplus.com/reference/cstdlib/malloc/
    char* product = (char *) malloc( (result_len + 1) * sizeof(char) );

    // 初始化result结果数组, 结果仍然保存在字符数组中
    memset(product, 0, result_len);
    product[result_len] = '\0';  // C语言中字符串以 \0 结尾

    // 计算乘积, 模拟小学乘法算法, 第一个数每一位乘第二个数每一位,最后解决进位.
    int* tempDigits = (int*) malloc(result_len * sizeof(int));
    memset(tempDigits, 0, result_len * sizeof(int));

    int pos1 = 0, pos2 = 0; // 记录两个数当前处理的位置
    // 注意pos1 + pos2 作为tempDigits中的下标，计算完乘积后数位是倒排的。即排首的是个位结果。
    for (int i = num1_len - 1; i >= 0; i--)
    {
        pos2 = 0;
        for (int j = num2_len - 1; j >= 0 ; j--)
        {
            tempDigits[pos1 + pos2] += (num1[i] - '0') * (num2[j] - '0');
            pos2++;
        }
        pos1++;
    }

    // 解决进位, 并将进位结果存回字符数组, 用于最终解决前导0
    int digit_count = 0; // 用于记录在结果字符数组中最高位数字的位置，便于最终倒序输出字符.
    for (int i = 0; i < result_len; i++)
    {
        int digit = tempDigits[i] % 10; // 第 i 位最终结果
        int carry = tempDigits[i] / 10; // 第 i 位需要向前一位的进位值
        if (i + 1 < result_len)
        {
            tempDigits[i + 1] += carry;
        }
        product[digit_count++] = '0' + digit; // 完成计算一位数字, 个位在前, 注意反向.
    }

    // 输出最终结果
    int skip = 1;
    for (int i = digit_count - 1; i >= 0 ; i--)
    {
        if (product[i] == '0' && skip)
        {
            skip = 0;
            continue; // 跳过前导0
        }
        skip = 0; // 无前导0
        putchar(product[i]);
    }
    putchar('\n');

    free(product); // 释放内存
    return 0;
}