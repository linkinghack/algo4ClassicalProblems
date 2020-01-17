#include <iostream>
#include <algorithm>

/**
 * 利用二分查找策略搜索目标元素在数组中的下标位置
 * 目标数组元素应为基本类型，数组应有序(升序)
 * param:
 *  array: T[]  待搜索数组
 *  start: int 搜索区域开始下标
 *  end: int 搜索区域结束下标
 *  target: T   搜索目标
 * return: int 搜索到的下标，或搜索失败时:-1
**/
template<class T>
int BinarySearch(T array[],int start,int end,T target){
    int position = -1;
    int mid = (start+end) / 2;
    while(start<=end){
        if(array[mid] == target){
            position = mid;
            break;
        }else if(array[mid]>target){
            end = mid - 1;
            mid = (start+end) / 2;
        }else {
            start = mid + 1;
            mid = (start+end) / 2;
        }
    }
    return position;
}

int main(){
    // 测试
    int arr[] = {2,5,6,8,12,34,48,57,78,91};
    int pos = BinarySearch(arr,0,9,10);
    std::cout<<"搜索得下标: "<<pos<<std::endl;
}