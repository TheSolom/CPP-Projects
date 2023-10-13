#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll x;
	cin >> x;

	int i = 1, j = 1;
	while (true)
	{
		while (true)
		{
			if (2 * i + 3 * j == x)
			{
				cout << i << " " << j;
				break;
			}
			++j;
		}
		++i;
	}
}
