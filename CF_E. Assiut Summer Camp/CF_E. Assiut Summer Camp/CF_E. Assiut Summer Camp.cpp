#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;


	while (T--)
	{
		vector<pair<int, string>> mp(4);
		mp[0].second = "Hussien";
		mp[1].second = "Atef";
		mp[2].second = "Karemo";
		mp[3].second = "Ezzat";

		cin >> mp[0].first >> mp[1].first >> mp[2].first >> mp[3].first;

		sort(mp.rbegin(), mp.rend());

		cout << mp[0].second << " " << mp[1].second << "\n";
	}
}