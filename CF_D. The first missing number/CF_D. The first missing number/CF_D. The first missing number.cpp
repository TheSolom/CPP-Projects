#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> neg(200000, 0);
	vector<int> pos(200000, 0);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x >= 0)
			pos[x] = 1;
		else
			neg[-1 * x] = 1;
	}

	for (int i = m; i > 0; i--)
	{
		if (neg[i] == 0)
		{
			cout << -i;
			return 0;
		}
	}

	for (int i = 0; i <= m; i++)
	{
		if (pos[i] == 0)
		{
			cout << i;
			return 0;
		}
	}
}