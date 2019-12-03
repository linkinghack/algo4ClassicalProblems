#include <stdio.h>

// 在有序列表中正确位置插入新数据
// 原顺序未知
int main() {
    int nums[16] = {0};
    int originalCount = 0;
    // 输入原列表时用于临时存储
    int temp = 0; 
    scanf("%d", &temp);
    int i = 0;
    while(temp != 0) {
        nums[i] = temp;
        scanf("%d", &temp);
        i++;
    }
    originalCount = i;
    i--; // 将下标放回到最后一个有效数字位置

    // 输入新数据
    int newNum = 0;
    scanf("%d", &newNum);
    if (nums[0] > nums[i]) {
        // 倒序
        while(newNum > nums[i]) {
            nums[i+1] = nums[i]; // 后移
            i--;
        }
        nums[i+1] = newNum;
    } else {
        // 正序
        while(newNum < nums[i]) {
            nums[i+1] = nums[i]; // 后移
            i--;
        }
        nums[i+1] = newNum;
    }

    // 输出最终数组
    for(int j = 0; j < originalCount + 1; j++) {
        printf("%d ", nums[j]);
    }

    return 0;
}