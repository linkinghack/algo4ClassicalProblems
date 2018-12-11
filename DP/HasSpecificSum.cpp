/* 从给定集合中选出和为给定值的元素 */
#include <iostream>

using namespace std;
bool rec_subset( int arr[], int i, int s );
bool dp_subset(int arr[], int len, int s);
int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    cout<<"Normal method: "<<endl;
    cout<<"Has specific sum?  :"<<rec_subset(arr,5,9)<<endl;
    cout<<"Has specific sum?  :"<<rec_subset(arr,5,10)<<endl;
    cout<<"Has specific sum?  :"<<rec_subset(arr,5,11)<<endl;
    cout<<"Has specific sum?  :"<<rec_subset(arr,5,12)<<endl;
    cout<<"\n\n\n\nDP method: "<<endl;
    cout<<"Has specific sum?  :"<<dp_subset(arr,6,9)<<endl;
    cout<<"Has specific sum?  :"<<dp_subset(arr,6,10)<<endl;
    cout<<"Has specific sum?  :"<<dp_subset(arr,6,11)<<endl;
    cout<<"Has specific sum?  :"<<dp_subset(arr,6,12)<<endl;
    return 0;
}

/*
** arr = {2. 34. 4. 12. 5. 2}
* 例如： 目标和为 9
* Subset(arr[5], 9)
    i      选              或  不选
    --> Subset(arr[4], 7)  或  Setset(arr[4], 9)
* arr[i], sum
*   1. sum == 0;  return true.  sum为0的时候说明之前比较过的已经满足，不需要继续
*   2. i == 0;  即仅剩下一个数字，sum却不为0，则 当且仅当 arr[0] == sum 时，return true;
*   3. if arr[i] > s: return Subset(arr[i-1], sum)

*   Subset(arr, i, s)
*  选当前： Subset(arr, i-1, s-arr[i])
*  不选当前：  Subset(arr, i-1, s)
*/

// Normal
bool rec_subset( int arr[], int i, int s ) {
    if ( s == 0 )
        return true;
    else if ( i == 0)
        return arr[0] == s;
    else if (arr[i] > s)
        return rec_subset(arr, i-1, s); // 当前值大于所需和，不选
    else {
        bool A = rec_subset(arr, i-1, s-arr[i]);  // 选中arr[i]
        bool B = rec_subset( arr, i-1, s); // 不选arr[i]
        return A || B;
    }
}

/*
*  DP 方式
*  保存 subset 表
*/
bool dp_subset(int arr[], int len, int s) {
    bool ss_table[len][s+1];  // 保存 subset(arr, i, s) 所有i,s的情况
    // 1. s == 0 的列，全为true
    for(int i = 0; i < len; i++){
        ss_table[i][0] = true;
    }

    // 2. i == 0 的所有情况都为false, 除了 arr[0] == s的情况
    for( int i=0; i < s; i++) {
        ss_table[0][i] = false;
    }
    ss_table[0][ arr[0] ] = true;

    // 3. 生成表的其他部分
    for (int i=1; i < len; i++) {
        for (int j=1; j < s+1; j++){
            if( arr[i] > j) // 当前值超过所需和
                ss_table[i][j] = ss_table[i-1][j];
            else {
                bool A = ss_table[i-1][j-arr[i]]; // 选
                bool B = ss_table[i-1][j]; // 不选
                ss_table[i][j] = A || B;
            }
        }
    }

    return ss_table[len-1][s];
}
