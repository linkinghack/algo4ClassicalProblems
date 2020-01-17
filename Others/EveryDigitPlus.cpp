/* 给定一个整数，将每一位上的值相加得到一个新数
    若值大于9，则继续执行操作。
    统计生成的数字的个数(包括本身)
*/

#include <iostream>
using namespace std;
int CountGeneratingRecurrently(int num, int cnt);
int CountGenerated(int num);

int main() {
    // cout<<"Total generated: "<<CountGenerating(123,1)<<endl;
    cout<<"Total generated: "<<CountGenerated(345)<<endl;
    return 0;
}

int CountGenerated(int num) {
    int count = 1;
    while(num > 9) {
        int temp = 0;
        while(num > 0){
            temp += num % 10;
            num /= 10;
        }
        count++;
        cout<<"generated: "<<temp<<endl;
        if(temp > 9) num = temp;
    }
    return count;
}

int CountGeneratingRecurrently(int num, int cnt) {
    if(num<10){
        cout<<"generated: "<<num<<endl;
        return cnt;
    }else {
        int temp = 0;
        while(num > 0){
            temp += num % 10;
            num /= 10;
        }
        return CountGeneratingRecurrently(temp,cnt+1);
    }
}