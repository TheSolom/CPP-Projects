#include <iostream>
#include <algorithm>  
using namespace std;

int arr_max(int arr[], int n) 
{
	if (n == 0)
		return arr[0];

	return max(arr[n], arr_max(arr, n-1));
}


int main()
{
	int arr[5] = {1, 8, 2, 10, 3};
	cout << arr_max(arr, 4);
}