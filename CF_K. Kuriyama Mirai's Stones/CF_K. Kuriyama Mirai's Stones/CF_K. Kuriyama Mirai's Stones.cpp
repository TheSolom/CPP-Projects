#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

	vector<int> vec(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> vec[i];

	vector<long long> sum(n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + vec[i];

	vector<int> v2 = vec;
	sort(v2.begin(), v2.end());

	vector<long long> sum2(n + 1);
	for (int i = 1; i <= n; i++)
		sum2[i] = sum2[i - 1] + v2[i];

	int t;
	cin >> t;
	while (t--)
	{
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1)
		{
			cout << sum[r] - sum[l - 1] << "\n";
		}
		else
		{
			cout << sum2[r] - sum2[l - 1] << "\n";
		}
	}
}