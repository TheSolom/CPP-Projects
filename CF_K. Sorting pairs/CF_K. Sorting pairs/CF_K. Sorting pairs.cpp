#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return (a.second > b.second);
}

int main()
{
	int n;
	cin >> n;

	vector<pair<string,int>> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	
	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << vec[i].first << " " << vec[i].second << "\n";
}