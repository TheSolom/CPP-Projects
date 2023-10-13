#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;

		vector<int> vec(n + 1, 0);
		vector<int> vec2(q);

		for (int i = 0; i < q; i++)
			cin >> vec2[i];

		for (int i = 0; i < q; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j % vec2[i] == 0)
					vec[j] = 1;
			}
		}

		for (int i = 1; i <= n; i++)
			cout << vec[i] << " ";
		cout << "\n";
	}
}