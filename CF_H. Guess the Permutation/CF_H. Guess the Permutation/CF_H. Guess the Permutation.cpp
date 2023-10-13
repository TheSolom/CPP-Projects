#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> vec[i][j];

	vector<bool> vis(n + 1, false);
	for (int i = 0; i < n; i++)
	{
		sort(vec[i].begin(), vec[i].end());

		if (!vis[vec[i][n - 1]])
		{
			cout << vec[i][n - 1] << " ";
			vis[vec[i][n - 1]] = true;
		}
		else
		{
			cout << n << " ";
		}
	}
}