#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char* sorted = new char[n];
    char* arr = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sorted[i];
        arr[i] = sorted[i];
    }
    sort(sorted, sorted + n);

    for (int i = 0; i < n; i++)
    {
        if (count(arr, arr + n, 3);)
        {

        }
    }
}