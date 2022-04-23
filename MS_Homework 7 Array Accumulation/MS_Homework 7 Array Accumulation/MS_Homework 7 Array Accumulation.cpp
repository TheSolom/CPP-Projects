#include <iostream>
using namespace std;

void accumulate_arr(int arr[], int n)
{
    if (n == 1)
        return;

    accumulate_arr(arr, n - 1);

    arr[n - 1] += arr[n - 2];
}

int main()
{
    int arr[6] = { 1, 2, 3, 4, 5, 6 };

    accumulate_arr(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}