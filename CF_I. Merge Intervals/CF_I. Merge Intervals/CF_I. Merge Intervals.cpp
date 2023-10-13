#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;

	sort(vec.begin(), vec.end());

	vector<pair<int, int>> v2;
	v2.push_back({ vec[0].first, vec[0].second });

	int idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (v2[idx].second >= vec[i].first)
		{
			v2[idx].second = max(v2[idx].second, vec[i].second); //what if [1,5] and [2,4]-> we want it [1,5]
		}
		else
		{
			idx++;
			v2.push_back({ vec[i].first, vec[i].second });
		}
	}

	for (int i = 0; i < v2.size(); i++)
		cout << v2[i].first << " " << v2[i].second << "\n";
}