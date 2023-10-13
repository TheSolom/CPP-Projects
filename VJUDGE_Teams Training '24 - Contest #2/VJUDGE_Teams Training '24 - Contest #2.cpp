#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void a() {
	int t;
	while (t--)
	{
		int n, a, b;
		cin >> n >> a >> b;

		vector<pair<int, bool>> vec(n, {0, false});
		for (int i = 0, inc = 1; i < n; i++)
			vec[i].first = inc++;

		vector<int> ans(n);
		ans[0] = a, vec[a - 1].second = true;
		//ans[n - 1] = b, vec[b - 1].second = true;

		for (int i = n - 1, pos = 1; i > 0; i--) {
			if (vec[i].first > a && !vec[i].second) {
				ans[pos++] = vec[i].first;
				vec[i].second = true;
			}
		}

		if (ans.size() == 3) {
			for (int i = 1, pos = n - 2; i < n; i++) {
				if (vec[i].first > a && !vec[i].second) {
					ans[pos--] = vec[i].first;
					vec[i].second = true;
				}
			}
		}
		else {
			cout << -1 << "\n";
			break;
		}

		if (ans.size() == n) 
			for (int i = 0; i < n; i++)
				cout << ans[i];
		else
			cout << -1 << "\n";
	}
}

void b() {
	int t;
	cin >> t;

	while (t--)
	{
		long long n, m;
		cin >> n >> m;


		cout << (n * m / 3) + ((n * m % 3) != 0) << "\n";
	}
}

void g() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;

		int i = 0, j = n - 1, palindrome = 0;
		pair<char, int> removed{ ' ', -1 };
		bool flag = false;
		while (i < j)
		{
			if (s[i] != s[j])
			{
				if (s[i] == removed.first)
					removed.second++;
				else if (s[j] == removed.first)
					removed.second++;
				else if (s[i + 1] == s[j]) {
					if (!flag)
						removed.first = s[i], removed.second += 2, palindrome++, flag = true;
				}
				else if (s[j - 1] == s[i]) {
					if (!flag)
						removed.first = s[j], removed.second += 2, palindrome++, flag = true;
				}
			}
			else
				i++, j--;
		}

		if (!palindrome)
			cout << -1 << "\n";
		if (palindrome && !flag)
			cout << 0 << "\n";
		else if (palindrome && flag)
			if (palindrome * 2 == n - removed.second)
				cout << removed.second << "\n";
			else
				cout << -1 << "\n";
	}
}

int main()
{
	b();
}