#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

	vector<int> freq(n + 1, 0);
	int table{}, max{};
	for (int i = 0; i < 2*n; i++)
	{
		int x;
		cin >> x;

		freq[x]++;

		if (freq[x] == 2)
			table--;
		else
			table++;

		if (max < table)
			max = table;
	}

	cout << max;
}