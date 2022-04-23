#include <iostream>
using namespace std;

char arr[4][4];

bool test()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j + 1])
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			char original = arr[i][j];
			if (test())
			{
				cout << "YES";
				return 0;
			}
			else
			{
				if (arr[i][j] == '#')
					arr[i][j] = '.';
				else
					arr[i][j] = '#';

				if (test())
				{
					cout << "YES";
					return 0;
				}
			}
			arr[i][j] = original;
		}
	}

	cout << "NO";
}