#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

void g() {
	string s;
	getline(cin, s);

	stringstream ss(s);

	int num;
	vector<int> vec;
	while (ss >> num)
		vec.push_back(num);

	bool flag = false;
	for (int i = 0; i < vec.size(); i++)
	{
		if (i && vec[i] < vec[i - 1]) {
			flag = true;
			break;
		}
		if (vec[i] < 100 || vec[i] > 675)
		{
			flag = true;
			break;
		}
		if (vec[i] % 25)
		{
			flag = true;
			break;
		}
	}

	if (flag) cout << "No";
	else cout << "Yes";
}

void d() {
	int n;
	cin >> n;

	cin.ignore();
	string s;
	getline(cin, s);
	stringstream ss(s);

	int num;
	vector<int> vec;
	while (ss >> num)
		vec.push_back(num);

	long long sum{};
	for (int i = 1; i <= vec.size(); i++)
	{
		if (i % 7 == 0) {
			cout << sum + vec[i - 1] << " ";
			sum = 0;
		}
		else
			sum += vec[i - 1];
	}
}

void a() {
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, x, y, left{}, right{}, up{}, down{};
		cin >> a >> b >> x >> y;
		x++, y++;

		if (x - 1 > 0)
		{
			up = ((x - 1) * b);
		}
		if (x + 1 <= a)
		{
			down = ((a - (x)) * b);
		}
		if (y - 1 > 0)
		{
			left = ((y - 1) * a);
		}
		if (y + 1 <= b)
		{
			right = ((b - (y)) * a);
		}

		cout << max({ left, right, up, down }) << "\n";
	}
}

bool palindrome(string s) {
	string P = s;
	reverse(P.begin(), P.end());

	if (s == P)
		return true;
	return false;
}
void f() {
	int n;
	cin >> n;

	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			if (palindrome(vec[i] + vec[j])) {
				cout << "Yes";
				return;
			}
		}
	}
	cout << "No";
}

void h() {
	int n, m;
	cin >> n >> m;

	vector<string> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	map<string, int> mp;
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		mp[s] = i;
	}

	vector<int> price(m + 1);
	for (int i = 0; i <= m; i++)
		cin >> price[i];

	long long sum{};
	for (int i = 0; i < n; i++)
	{
		if (mp.count(vec[i]) == 1)
			sum += price[mp[vec[i]]];
		else
			sum += price[0];
	}

	cout << sum << "\n";
}

void e() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<int> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];

		vector<int> ans(n);
		ans = vec;

		int maxi = 0;
		for (int i = n - 1; i >= 0; i--) 
		{
			int x = i + vec[i];
			if (x < n) 		
				ans[i] += ans[x]; 

			maxi = max(maxi, ans[i]);
		}

		cout << maxi << "\n";
	}
}

int main()
{
	e();
}