#include <iostream>
#include <time.h>

using namespace std;
long long FrogJumpDPRecursive(long long n);
long long FrogJumpDP(int n);

int main()
{
    int n;
    cin>>n;
    cout<<"Tick per second: "<< CLOCKS_PER_SEC<< endl;
    clock_t start = clock();
    cout<<"DP Iteration: "<<FrogJumpDP(n)<<endl;
    clock_t stop = clock();
    cout<<"DP Iteration Time consumption: " << stop - start<<endl;

    start = clock();
    cout<<"DP Recursive: "<<FrogJumpDPRecursive(n)<<endl;
    stop = clock();
    cout<<"DP Recursive Time consumption: " << (stop - start) / CLOCKS_PER_SEC <<" s"<<endl;
    cout<<"DP Recursive Time consumption: " << (stop - start) <<" ticks"<<endl;

    return 0;
}

long long FrogJumpDPRecursive(long long n)
{
    if (n < 1)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Solve sub-problems
    return FrogJumpDPRecursive(n - 1) + FrogJumpDPRecursive(n - 2);
}

long long FrogJumpDP(int n)
{
    if (n < 1)
    {
        // error
        return -1;
    }

    long long sub_ans[3] = {0, 1, 2}; // skip index 0

    if (n <= 2)
    {
        return sub_ans[n];
    }

    // n > 2
    // First step = 1 or 2; then add sub solutions
    for (int i = 3; i <= n; i++)
    {
        long long preStepTemp = sub_ans[2];
        sub_ans[2] = sub_ans[2] + sub_ans[1];
        sub_ans[1] = preStepTemp;
    }
    return sub_ans[2];
}