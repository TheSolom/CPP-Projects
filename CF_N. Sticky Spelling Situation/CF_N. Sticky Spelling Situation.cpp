#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	string sa, sb;
	cin >> n >> sa >> sb;

	vector<int> fr(26);
	for (int i = 0; i < n; i++)
		fr[sa[i] - 'a']++;

	int cnt{};
	for (int i = 0; i < n; i++)
	{
		if (fr[sb[i] - 'a']  < 1)
			cnt++;
		else
			fr[sb[i] - 'a']--;
	}

	cout << cnt;
}