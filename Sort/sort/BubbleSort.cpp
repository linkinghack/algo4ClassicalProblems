#include <iostream>

/**
 * 对指定数组的部分区域进行冒泡排序
 * param: 
 *  array: T[]  待排序数组，元素仅为基本类型
 *  start: 排序区域开始下标
 *  end: 排序区域结束下表(不包含)
 *  reverse: 是否降序, 默认false
**/
template<class T>
void BubbleSort(T array[],int start,int end,bool reverse=false){
    for(;start<end;start++){
        for(int i=start;i<end;i++){
            if(array[i]<array[start] && !reverse
                || array[i]>array[start] && reverse){
                    T temp = array[i];
                    array[i] = array[start];
                    array[start] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {8,7,6,5,4,3,2,1};
    BubbleSort(arr,0,7);
    for(int i=0;i<8;i++){
        std::cout<<arr[i]<<" ";
    }
}

