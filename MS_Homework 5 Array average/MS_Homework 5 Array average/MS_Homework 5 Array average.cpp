#include <iostream>
using namespace std;

double average1(int arr[], int n)
{
	double result = arr[n - 1] / 5.0;

	if (n == 1)
		return result;

	return result + average1(arr, n - 1);
}

double average2(int arr[], int n)
{
	if (n == 1)
		return arr[0];

	if (n == 5)
		return (arr[n - 1] + average2(arr, n - 1)) / 5.0;

	return arr[n - 1] + average2(arr, n - 1);
}

int main()
{
    int arr[5] = { 1, 8, 2, 10, 3 };

    cout << average1(arr, 5) << endl;

	cout << average2(arr, 5) << endl;
}