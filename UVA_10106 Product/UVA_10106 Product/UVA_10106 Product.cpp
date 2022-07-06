#include <iostream>
using namespace std;

int main()
{
	string x, y;

	while (cin >> x)
	{
		cin >> y;

		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());

		int size = x.length() + y.length();
		int* arr = new int[size] {};

		for (int i = 0; i < x.length(); i++)
		{
			for (int j = 0; j < y.length(); j++)
			{
				arr[i + j] += (x[i] - '0') * (y[j] - '0');
			}
		}


		for (int i = 0; i < size - 1; i++)
		{
			arr[i + 1] += arr[i] / 10;
			arr[i] %= 10;
		}

		int i = size - 1;
		while (arr[i] == 0)
			i--;

		for (; i >= 0; i--)
			cout << arr[i];
		cout << endl;

		delete[]arr;
	}
}