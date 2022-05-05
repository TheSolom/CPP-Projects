#include <iostream>
using namespace std;

int Prefix_Sum(int arr[], int len, int val)
{
    if (val == 0)
        return 0;

    return arr[val - 1] + Prefix_Sum(arr, len, val - 1);
}

int Prefix_SumV2(int arr[], int len, int val)
{
    if (val == 0)
        return 0;

    return arr[0] + Prefix_Sum(arr + 1, len, val - 1);
}

int main()
{
    int arr[5] = { 1,3,4,6,7 };

    //cout << Prefix_Sum(arr, 5, 3) << endl;
    cout << Prefix_SumV2(arr, 5, 3) << endl;
}