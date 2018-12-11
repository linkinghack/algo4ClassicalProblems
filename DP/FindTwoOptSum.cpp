#include <iostream>
#include <algorithm>

using namespace std;

int rec_opt( int arr[], int i );
int dp_opt( int arr[], int size, int i );

int main() {
    int arr[] = {1, 2, 4, 1, 7, 8, 3};

    cout<<"optimized sum: "<<rec_opt(arr,6)<<endl;
    cout<<"optimized by DP: "<<dp_opt(arr,6,6)<<endl;
    return 0;
}

// Normal method
int rec_opt( int arr[], int i ) {
    if( i== 0 ) {
        return arr[0]; 
    } 
    else if( i == 1 ) {
        return max( arr[0], arr[1] );
    }
    else {
        int A = rec_opt( arr, i-2 ) + arr[i]; // 选i
        int B = rec_opt( arr, i-1) ;  // 不选i
        return max( A, B );
    }
}

// DP
int dp_opt( int arr[], int size, int i ) {
    // initial opt table
    int opt_table[size] = {0};
    opt_table[0] = arr[0];
    opt_table[1] = max( arr[0], arr[1] );

    for( int j = 2; j < size; j++ ) {
        int A = opt_table[j-2] + arr[j];
        int B = opt_table[j-1];
        opt_table[j] = max( A, B );
    }
    return opt_table[i];
}