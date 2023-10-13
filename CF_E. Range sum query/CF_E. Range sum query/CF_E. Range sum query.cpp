#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, q;
    cin >> n >> q;

	vector<long long> sum(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		int x; 
		cin >> x;

		sum[i] = sum[i - 1] + x;
	}

	while (q--)
	{
		int l, r;
		cin >> l >> r;

		cout << sum[r] - sum[l - 1] << "\n";
	}
}