#include <iostream>

using namespace std;
int main(){
    // 绘制指定层数的等腰三角形
    int n = 0;
    cout<<"input number of piles: "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--) cout<<" "; //打印空格
        for(int k=1;k<=i;k++) cout<<"*"; // 输出 层数个*
        for(int m=i-1;m>=1;m--) cout<<"*"; // 输出 层数-1 个*

        cout<<endl;
    }
    cout<<endl;
}