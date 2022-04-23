#include <iostream>
using namespace std;

void left_max(int arr[], int n) 
{
    if (n == 1)
        return;

    left_max(arr, n - 1);
    arr[n - 1] = max(arr[n - 1], arr[n - 2]);
}

int main()
{
    int arr[6] = { 1, 3, 5, 7, 4, 2 };

    left_max(arr, 6);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}