#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, k;
	cin >> n >> k;
	int covered = 0;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		covered += r - l + 1;
	}

	covered %= k;

	if (covered != 0)//or covered = (k - covered) % k;
	covered = k - covered;
				
	cout << covered;

	//or insted of above use: covered = (k - covered % k) % k;

 /*or
	set <int> set;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;

		for (int i = l; i <= r; i++)
			set.insert(i);
	}

	int count =  0, cntr = set.size();

	while (true)
	{
		if (cntr++ % k == 0)
		{
			cout << count;
			return 0;
		}
		count++;
	}*/
}