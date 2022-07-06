#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	int step, mod;

	while (cin >> step >> mod)
	{
		bool* arr = new bool[mod] {};

		bool flag = false;
		int index = 0, num = -1;
		for (int i = 1; i <= mod - 1; i++, index += step)
		{
			num = index % mod;
			if (arr[num] == true)
			{
				flag = true;
				break;
			}

			arr[num] = true;
			index = num;
		}

		if (flag)
		{
			cout << setw(10) << step << setw(10) << mod << "    Bad Choice\n\n";
		}
		else
		{
			cout << setw(10) << step << setw(10) << mod << "    Good Choice\n\n";
		}

		delete[]arr;
	}
}