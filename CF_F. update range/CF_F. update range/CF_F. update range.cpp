#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, q;
	cin >> n >> q;

	vector<int> vec(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> vec[i];

	vector<int> add(n + 2, 0);

	while (q--)
	{
		int l, r, val;
		cin >> l >> r >> val;

		add[l] += val;
		add[r + 1] -= val;
	}

	for (int i = 1; i <= n; i++)
		add[i] += add[i - 1];

	for (int i = 1; i <= n; i++)
		cout << vec[i] + add[i] << " ";
}
