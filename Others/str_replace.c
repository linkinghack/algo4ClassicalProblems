#include <stdio.h>
#include <string.h>

// int N = 100;
#define N 100

int findStr(char source[], char target[]);
void strInsert(char source[], int position, char target[]);
void makeStrGap(char source[], int position, int gapSize);

int main() {
    char text[N] = "hello";
    char searchStr[20], newStr[20];
    
    gets(text); // 获取第一行 文章内容
    
    // 获取接下来的搜索目标和替换字符串，使用格式化输入
    scanf("%s %s", searchStr, newStr);
    while (strcmp(searchStr, "0") > 0 || strcmp(newStr, "0") > 0)
    {  // 在输入的两个串都为 "0" 才停止，仅一个"0" 时依然继续工作
        int searchLen = strlen(searchStr);
        int newLen = strlen(newStr);

        int position = findStr(text, searchStr); // 找到第一次出现搜索目标的位置

        if (searchLen == newLen)  // 新字串和旧字串长度相等
        {
            strInsert(text, position, newStr);

        } else if (searchLen < newLen)  // 新字串比旧子串长
        {
            makeStrGap(text, position + searchLen, newLen - searchLen); // 在待替换部分后边腾出需要的newLen - searchLen 个空间

        } else { // 新子串比旧子串短

            makeStrGap(text, position + newLen, newLen - searchLen); // 只留下放置新子串的位置，多出来的都覆盖掉
        }

        strInsert(text, position, newStr); // 将新串写入
        scanf("%s %s", searchStr, newStr);
    }

    printf("%s", text);
    return 0;
}


// 在source[] 的 position 位置前边腾出 gapSize 个空位 
// gapSize 为负时，表示向前移动
void makeStrGap(char source[], int position, int gapSize) {
    int sourceLen = strlen(source);

    if (gapSize == 0)
    {
       return;
    }
    
    if (gapSize < 0)  // gapSize < 0 即将position位置以及之后的字符都向前移动，移动多长source就丢失多少个字符
    {
        gapSize = -gapSize;
        for (int i = position; i <= sourceLen; i++)  // 此处 i<=sourceLen 是因为需要将结尾的 \0 也向前移动
        {
            source[i] = source[i + gapSize]; // 每个字符都向前移动gapSize个位置
        }
        
    } else {   // gapSize > 0 时 即普通的后移腾处位置

        // 从\0 结尾字符开始，后移
        // source[sourceLen] 目前刚好是 \0
        for (int i = sourceLen; i >= position; i--)
        {
            source[i + gapSize] = source[i];
        }
    }
}


// 在source[] 的 第 position 个位置上, 插入 target[]
// 无需考虑覆盖问题，直接将target字符串插入到position位置
void strInsert(char source[], int position, char target[]) {
    int targetLen = strlen(target);

    // 将target字符串插入到目标位置，注意不要把\0也插入
    // i < targetLen 即可保证在target串的\0前停下
    // 因为 target[targetLen] 的位置是 \0
    for (int i = 0; i < targetLen; i++)
    {
        source[position + i] = target[i];
    }
}


// 在source 中搜索 target字串
// 返回target字串第一次出现的位置的下标
// 若未找到，则返回-1
int findStr(char source[], char target[]) {
    int sourceLen = strlen(source);
    int targetLen = strlen(target);

    for (int i = 0; i < sourceLen; i++)
    {
        if (source[i] == target[0])
        {
            int equal = 1, tempI = i;
            for(int j =0; j < targetLen; j++)
            {
                if (target[j] == source[tempI])
                {
                    tempI++;
                } else {
                    equal = 0;
                    break;
                } 

                if (j >= sourceLen)  // target比较范围已经超出source的长度，一定不存在
                {
                    equal = 0;
                    break;
                }
            }

            if (equal == 1)
            {
                return i;
            }
        }
    }
    
    return -1;
}