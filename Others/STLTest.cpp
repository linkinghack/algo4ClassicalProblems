#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    nums[3] = 123;

    for (size_t i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    cout<<"Capatity: " << nums.capacity() <<endl;
    
    
    return 0;
}