#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;

	long long last = str.length() - 1, cntr1 = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '1')
		{
			cntr1++;
		}
	}

	if (last % 2 != 0) //Odd
	{
		cout << last / 2 + 1;
	}
	else if (cntr1 > 1) //Even With ones
	{
		cout << last / 2 + 1;
	}
	else //Even only
	{
		cout << last / 2;
	}
}