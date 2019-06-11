#include <iostream>
#include <cmath>

bool IsNarcissisticNumber(int);

int main(){
    for(int i=100;i<=999;i++){
        if(IsNarcissisticNumber(i))
            std::cout<<i<<" ";
    }
}

/**
 * 判断一个数是否是水仙花数
 * param: i int - 待判断数
 * return: bool - true:是水仙花数, false:不是水仙花数
**/
bool IsNarcissisticNumber(int i){
    if(i<100 || i>999) return false;
    int sum = 0;
    int ii = i; //备份目标数
    while(i>0){
        int temp = i%10;
        sum += std::pow(temp,3);
        i /= 10;
    }
    if(sum == ii) return true;
    else return false;   
}