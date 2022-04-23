#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
	if (n == 0)
	{
		return arr[0];
	}

	return arr[n] + sum(arr, n - 1);
}

int main()
{
    int arr[5] = {1, 8, 2, 10, 3};
    cout << sum(arr, 4);
}