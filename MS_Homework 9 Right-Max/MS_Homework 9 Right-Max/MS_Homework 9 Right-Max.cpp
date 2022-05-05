#include <iostream>
using namespace std;

void left_max(int arr[], int len, int start_position = 0)
{
    if (start_position == len - 1)
        return;

    left_max(arr, len, start_position + 1);
    arr[start_position] = max(arr[start_position], arr[start_position + 1]); 
}

void left_maxV2(int arr[], int len) 
{
    if (len == 1)
        return;

    left_maxV2(arr + 1, len - 1); //arr+1 is the a new array shifted. {1, 8, 2, 10, 3} => {8, 2, 10, 3}
    arr[0] = max(arr[0], arr[1]); //Then we only need to think about arr (0)
}

int main()
{
    int arr[6] = { 1,3,5,7,4,2 };
    //left_max(arr, 6, 0);
    left_maxV2(arr, 6);

    for (int x : arr)
        cout << x << " ";
}