#include <iostream>
#include <cstdio>
#define KeyType int
#define MAXSIZE 50

using namespace std;

void StraightInsertionSort(KeyType L[],int length){
    int i = 0, j = 0;
    int count = 0;
    for(i = 2; i<=length; i++){
        printf("i=%d, L[0]=%d, L[i]=%d ",i,L[0],L[i]);
        L[0] = L[i];  // 设置哨兵
        for(j = i-1; L[0]<L[j];j--){  // i-1 是有序部分中最后一个元素
            L[j+1] = L[j]; // 后移
            count++;
        } // j 最终为正确位置
        printf("j=%d ",j);
        L[j+1] = L[0]; // 放置
        printf("L[j]=%d \n",L[j]);
    }
    cout<<"Compared "<<count<<" times."<<endl;
}

int main(){
    int length = 20;
    KeyType l[] = {0,2,3,6,1,8,4,56,12,9,5,12,6,7,123,34,213,8,90,62,71};
    KeyType ll[] = {0,5,4,3,2,1};
    StraightInsertionSort(ll,5);

    for(int i=1; i<6; i++) {
        cout<<ll[i]<<" ";
    }
    cout<<endl;

    return 0;
}