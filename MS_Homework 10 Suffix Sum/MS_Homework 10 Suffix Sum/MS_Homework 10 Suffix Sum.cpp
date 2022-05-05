#include <iostream>
using namespace std;

int Suffix_Sum(int arr[], int len, int val)
{
    if (len == val)
        return arr[val - 1];

    return arr[len - 1] + Suffix_Sum(arr, len - 1, val);
}

int main()
{
    int arr[5] = { 1,3,4,6,8 };

    cout << Suffix_Sum(arr, 5, 3) << endl;
}