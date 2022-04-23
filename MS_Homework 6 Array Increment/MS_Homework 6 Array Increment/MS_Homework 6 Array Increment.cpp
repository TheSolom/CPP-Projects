#include <iostream>
using namespace std;

void array_increment1(int arr[], int n, int count)
{
    if (n == 0)
        return;

    array_increment1(arr, n - 1, count - 1);

    cout << count + arr[n - 1] << " ";
}

void array_increment2(int arr[], int n)
{
    if (n == 0)
        return;
    
    array_increment2(arr, n - 1);
    arr[n - 1] += n - 1;
}

int main()
{
    int arr1[4] = { 1, 2, 5, 9 };
    int arr2[5] = { 1, 8, 2, 10, 3 };

    array_increment1(arr1, 4, 3);
    cout << "\n";
    array_increment1(arr2, 5, 4);
    cout << "\n\n";


    array_increment2(arr1, 4);
    for (int i = 0; i < 4; i++)
        cout << arr1[i] << " ";

    cout << "\n";
    array_increment2(arr2, 5);   
    for (int j = 0; j < 5; j++)
        cout << arr2[j] << " ";

}