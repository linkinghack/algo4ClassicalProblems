#include <iostream>
#include <cstdio>
#define KeyType int
#define MAXSIZE 50

using namespace std;

void StraightInsertionSort(KeyType L[],int length){
    for(int i = 1; i < length; i++) {
        int j = i;
        KeyType temp = L[i];
        while (j > 0 && temp < L[j - 1]) {
            L[j] = L[j-1];
            j--; // 刚腾出的位置
        }
        L[j] = temp;
    }
}

int main(){
    KeyType ll[] = {5,4,3,2,1};
    StraightInsertionSort(ll,5);

    for(int i=0; i<5; i++) {
        cout<<ll[i]<<" ";
    }
    cout<<endl;

    return 0;
}