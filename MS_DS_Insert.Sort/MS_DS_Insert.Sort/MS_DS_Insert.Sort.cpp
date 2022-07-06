#include <iostream>
using namespace std;

//O(n^2) time in worst case and average case
//But O(n) in best case & O(1) space

void InsertSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        int j = i - 1;
        while (j > - 1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = { 3,2,4,9,7,2,7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    InsertSort(arr, n);

    for (int i : arr)
        cout << i << " ";
}


//for (int i = 1; i < n; i++)
//{
//    int key = arr[i];
//
//    int j;
//    for (j = i - 1; j > -1 && arr[j] > key; )
//    {
//        arr[j + 1] = arr[j];
//        j--;
//    }
//
//    arr[j + 1] = key;
//}