#include <iostream>
#include <algorithm>

/**
 * ���ö��ֲ��Ҳ�������Ŀ��Ԫ���������е��±�λ��
 * Ŀ������Ԫ��ӦΪ�������ͣ�����Ӧ����(����)
 * param:
 *  array: T[]  ����������
 *  start: int ��������ʼ�±�
 *  end: int ������������±�
 *  target: T   ����Ŀ��
 * return: int ���������±꣬������ʧ��ʱ:-1
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
    // ����
    int arr[] = {2,5,6,8,12,34,48,57,78,91};
    int pos = BinarySearch(arr,0,9,10);
    std::cout<<"�������±�: "<<pos<<std::endl;
}