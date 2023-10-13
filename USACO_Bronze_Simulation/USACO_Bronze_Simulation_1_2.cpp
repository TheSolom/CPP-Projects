#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

void TheLostCow() {
	// We can simulate this problem by running each step of Farmer John's movement.
	// At each step, we check Farmer John's starting position and his intended ending position,
	// and check to see whether that overlaps Bessie's position.
	// If it does not, then we add the full distance to a running total,
	// and move poor Farmer John back to his starting position. Otherwise, 
	// we add the distance between FJ's current position and Bessie's position to the running total,
	// and return that total as our answer.
	ofstream out("lostcow.out");
	ifstream in("lostcow.in");

	int x, y;
	in >> x >> y;

	long long mul = 1, cnt = 0, direction = true; // true => going right else left
	while (true)
	{
		if ((direction && y >= x && x + mul >= y) || (!direction && x >= y && y >= x - mul)) {
			cnt += abs(y - x);
			break;
		}

		mul *= 2;
		cnt += mul;
		direction = !direction;
	}

	out << cnt << "\n";
}

void TheBovineShuffle() {
	/*
		1  3  4  5  2
		11 55 22 33 44		output

		1  3  4  5  2   1st
		11 44 55 22 33

		1  3  4  5  2   2nd
		11 33 44 55 22

		1  3  4  5  2   3rd
		11 22 33 44 55      input
	*/
	ofstream out("shuffle.out");
	ifstream in("shuffle.in");

	int n, ai;
	in >> n;

	unordered_map<int, int> a(n);
	for (int i = 0; i < n; i++)
		in >> ai, a[ai] = i;

	vector<int> cows(n);
	for (int i = 0; i < n; i++)
		in >> cows[i];

	vector<int> prev_cows(n);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++)
		{
			int prev_loc = a[j + 1];
			prev_cows[prev_loc] = cows[j];
		}
		cows = prev_cows;
	}

	for (int i = 0; i < n; i++)
		out << cows[i] << "\n";
}
void TheBovineShuffle2() {
	int n;
	cin >> n;

	vector<int> shuffle(n);
	for (int& i : shuffle) { cin >> i; }
	vector<int> ids(n);
	for (int& i : ids) { cin >> i; }

	for (int i = 0; i < 3; i++) {
		vector<int> past_order(n);
		for (int j = 0; j < n; j++)
		{
			past_order[j] = ids[shuffle[j] - 1];
		}
		ids = past_order;
	}

	for (const int& i : ids) { cout << i << '\n'; }
}

void TheBucketList() {
	ifstream in("blist.in");
	ofstream out("blist.out");

	int n, ans{};
	in >> n;

	vector<int> prefixsum(1002, 0);

	for (int i = 0; i < n; i++) {
		int s, t, b;
		in >> s >> t >> b;

		prefixsum[s] += b; // += insted of = because if there is duplicates in s ot t
		prefixsum[t + 1] += -b;
	}

	for (int i = 1; i < 1002; i++)
	{
		prefixsum[i] += prefixsum[i - 1];

		ans = max(ans, prefixsum[i]);
	}

	out << ans;
}

void MeasuringTraffic() {
	// https://www.youtube.com/watch?v=RZBnIYC3GTw
	ofstream out("traffic.out");
	ifstream in("traffic.in");

	int n;
	in >> n;

	struct segment {
		string s;
		int a, b;
	};
	vector<segment> vec(n);
	for (int i = 0; i < n; i++)
		in >> vec[i].s >> vec[i].a >> vec[i].b;


	int ans_min = 0, ans_max = 1000;
	for (int i = n - 1; i >= 0; i--)
	{
		if (vec[i].s == "on") {
			ans_min -= vec[i].b;
			ans_max -= vec[i].a;
		}
		else if (vec[i].s == "off") {
			ans_min += vec[i].a;
			ans_max += vec[i].b;
		}
		else {
			ans_min = max(ans_min, vec[i].a);
			ans_max = min(ans_max, vec[i].b);
		}
	}
	out << max(0, ans_min) << " " << ans_max << "\n";

	ans_min = 0, ans_max = 1000;
	for (int i = 0; i < n; i++)
	{
		if (vec[i].s == "on") {
			ans_min += vec[i].a;
			ans_max += vec[i].b;
		}
		else if (vec[i].s == "off") {
			ans_min -= vec[i].b;
			ans_max -= vec[i].a;
		}
		else {
			ans_min = max(ans_min, vec[i].a);
			ans_max = min(ans_max, vec[i].b);
		}
	}
	out << max(0, ans_min) << " " << ans_max << "\n";
}

void CircularBarn() {
	ofstream out("cbarn.out");
	ifstream in("cbarn.in");

	int n;
	in >> n;

	vector<int> r(n);
	for (int i = 0; i < n; i++)
		in >> r[i];

	int ans = INT32_MAX;
	for (int i = 0; i < n; i++)
	{
		int cnt{}, inc{};
		for (int j = i, steps = 0; steps < n; steps++, j++) {
			j %= n;
			cnt += (r[j] * inc++);
		}

		ans = min(ans, cnt);
	}

	out << ans;
}

void BlockGame() {
	ofstream out("blocks.out");
	ifstream in("blocks.in");

	int n;
	in >> n;

	int amount[26] = {};
	for (int i = 0; i < n; i++)
	{
		string a, b;
		in >> a >> b;

		int amount_a[26]{}, amount_b[26]{};

		for (int j = 0; j < a.size(); j++)
			amount_a[a[j] - 'a']++;

		for (int j = 0; j < b.size(); j++)
			amount_b[b[j] - 'a']++;

		for (int j = 0; j < 26; j++)
			amount[j] += max(amount_a[j], amount_b[j]);
	}

	for (int i = 0; i < 26; i++)
		out << amount[i] << "\n";
}

char vec[3][3];
bool check3(char ch1, char ch2, char a, char vec, char c) {
	// All 3 characters have to be either ch1 or ch2
	if (a != ch1 && a != ch2) return false;
	if (vec != ch1 && vec != ch2) return false;
	if (c != ch1 && c != ch2) return false;

	// ch1 and ch2 have to appear at least once each
	if (a != ch1 && vec != ch1 && c != ch1) return false;
	if (a != ch2 && vec != ch2 && c != ch2) return false;

	return true;
}
int team_wins(char ch1, char ch2) {
	// Check diagonals
	if (check3(ch1, ch2, vec[0][0], vec[1][1], vec[2][2])) return 1;
	if (check3(ch1, ch2, vec[0][2], vec[1][1], vec[2][0])) return 1;

	// Check rows and columns
	for (int i = 0; i < 3; i++) {
		if (check3(ch1, ch2, vec[0][i], vec[1][i], vec[2][i])) return 1;
		if (check3(ch1, ch2, vec[i][0], vec[i][1], vec[i][2])) return 1;
	}
	return 0;
}
int cow_wins(char ch) {
	// Check diagonals
	if (vec[0][0] == ch && vec[1][1] == ch && vec[2][2] == ch) return 1;
	if (vec[0][2] == ch && vec[1][1] == ch && vec[2][0] == ch) return 1;

	// Check rows and columns
	for (int i = 0; i < 3; i++) {
		if (vec[0][i] == ch && vec[1][i] == ch && vec[2][i] == ch) return 1;
		if (vec[i][0] == ch && vec[i][1] == ch && vec[i][2] == ch) return 1;
	}

	return 0;
}
void TeamTicTacToe() {
	ofstream out("tttt.out");
	ifstream in("tttt.in");

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			in >> vec[i][j];

	int answer1 = 0, answer2 = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++)
		answer1 += cow_wins(ch);

	for (char ch1 = 'A'; ch1 <= 'Z'; ch1++)
		for (char ch2 = ch1 + 1; ch2 <= 'Z'; ch2++)
			answer2 += team_wins(ch1, ch2);

	out << answer1 << "\n" << answer2 << "\n";
}

set<set<char>> S[4];
void test(char a, char b, char c) {
	set<char> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	S[s.size()].insert(s);
}
void TeamTicTacToe2() {
	ofstream out("tttt.out");
	ifstream in("tttt.in");

	char a, b, c, d, e, f, g, h, i;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

	// a b c
	// d e f
	// g h i
	test(a, b, c);
	test(d, e, f);
	test(g, h, i);
	test(a, d, g);
	test(b, e, h);
	test(c, f, i);
	test(a, e, i);
	test(g, e, c);

	cout << S[1].size() << endl << S[2].size() << endl; // s[0] means no winners
}

void MowingtheField() {
	ifstream in("mowing.in");
	ofstream out("mowing.out");

	int n;
	in >> n;

	map<pair<int, int>, int> mp;
	char dir;
	int steps, x{}, y{}, cnt{}, ans = INT32_MAX;
	for (int i = 0; i < n; i++)
	{
		in >> dir >> steps;

		for (int j = 0; j < steps; j++)
		{
			cnt++;
			if (dir == 'N')
				y++;
			else if (dir == 'E')
				x++;
			else if (dir == 'S')
				y--;
			else
				x--;

			if (mp.count({ x, y }))
				ans = min(ans, cnt - mp[{x, y}]);
			mp[{x, y}] = cnt;
		}
	}

	out << (ans == INT32_MAX ? -1 : ans);
}

void DaisyChains() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int ans{};
	for (int i = 0; i < n; i++)
	{
		map<int, int> mp;
		for (int j = i, sum = 0, cnt = 1; j < n; j++, cnt++)
		{
			sum += vec[j], mp[vec[j]] = j;

			if (sum % cnt == 0)
				if (mp.count(sum / cnt))
					ans++;
		}
	}

	cout << ans;
}

void CountingLiars() {
	int n;
	cin >> n;

	vector<pair<char, int>> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;

	int ans = n;
	for (int i = 0; i < n; i++)
	{
		int cnt{};
		for (int j = 0; j < n; j++)
		{
			if ((vec[j].first == 'L' && vec[j].second < vec[i].second) ||
				(vec[j].first == 'G' && vec[j].second > vec[i].second))
				cnt++;
		}
		ans = min(ans, cnt);
	}

	cout << ans;
}

void CowGymnastics() {
	// https://www.youtube.com/watch?v=YV1rcD-sB00
	ifstream in("gymnastics.in");
	ofstream out("gymnastics.out");

	int k, n;
	in >> k >> n;

	vector<vector<int>> table(n, vector<int>(n));

	for (int session = 0; session < k; session++)
	{
		vector<int> vec(n);
		for (int i = 0; i < n; i++)
			in >> vec[i];

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				table[vec[i] - 1][vec[j] - 1]++;
	}

	int cnt{};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (table[i][j] == k)
				cnt++;

	out << cnt;
}

void BovineGenomics() {
	ifstream in("cownomics.in");
	ofstream out("cownomics.out");

	int n, m;
	in >> n >> m;

	vector<string> spotty(n);
	for (int i = 0; i < n; i++)
		in >> spotty[i];

	vector<string> plain(n);
	for (int i = 0; i < n; i++)
		in >> plain[i];

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		set<char> set;
		for (int j = 0; j < n; j++)
			set.insert(plain[j][i]);

		bool flag = true;
		for (int j = 0; j < n; j++)
		{
			if (set.count(spotty[j][i]) > 0)
			{
				flag = false;
				break;
			}
		}

		if (flag)
			ans++;
	}

	out << ans;
}

void Triangles() {
	ifstream in("triangles.in");
	ofstream out("triangles.out");

	int n;
	in >> n;

	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++)
		in >> vec[i].first >> vec[i].second;

	int maxArea{};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
			{
				if (vec[i].first == vec[j].first && vec[i].second == vec[k].second) {
					int area = abs((vec[k].first - vec[i].first) * (vec[j].second - vec[i].second));
					maxArea = max(maxArea, area);
				}
			}
		}
	}

	out << maxArea;
}

void Lifeguards() {
	ifstream in("lifeguards.in");
	ofstream out("lifeguards.out");

	int n, max_time{};
	cin >> n;

	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
		max_time = max(max_time, vec[i].second);
	}

	int max_cover = 0;
	for (int i = 0; i < n; i++) {
		int time_covered = 0;
		// Try to find a cow that can cover this interval
		for (int t = 1; t <= max_time; t++)
		{
			for (int j = 0; j < n; j++)
			{
				// Check that it's not the fired cow
				if (j != i) {
					if (vec[j].first <= t && vec[j].second > t) {
						// One more time slot covered - no need to search further
						time_covered++;
						break;
					}
				}
			}
		}
		max_cover = max(max_cover, time_covered);
	}

	cout << max_cover;
}

void LoadBalancing() {
	ifstream in("balancing.in");
	ofstream out("balancing.out");

	int n, b;
	in >> n >> b;

	vector<int> x_vals(n), y_vals(n);
	for (int i = 0; i < n; i++)
		in >> x_vals[i] >> y_vals[i];

	int ans{ 101 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			int x = x_vals[i] + 1, y = y_vals[j] + 1;

			int top_left{}, top_right{}, bottom_left{}, bottom_right{};
			for (int i = 0; i < n; i++)
			{
				if (x_vals[i] > x && y_vals[i] > y)
					top_right++;
				else if (x_vals[i] > x && y_vals[i] < y)
					bottom_right++;
				else if (x_vals[i] < x && y_vals[i] > y)
					top_left++;
				else if (x_vals[i] < x && y_vals[i] < y)
					bottom_left++;
			}

			ans = min(ans, max({ top_left, top_right, bottom_left, bottom_right }));
		}
	}

	out << ans;
}

void SleepinginClass() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<int> vec(n);
		int sum{};
		for (int i = 0; i < n; i++)
			cin >> vec[i], sum += vec[i];

		for (int r = n; r >= 1; r--)
		{
			if (sum % r)
				continue;

			int req_sum = sum / r;
			int cur_sum{};
			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				cur_sum += vec[i];
				if (cur_sum > req_sum) {
					// Can't split the array into r equal elements.
					ok = false;
					break;
				}
				else if (cur_sum == req_sum) {
					// Start a new range
					cur_sum = 0;
				}
			}

			if (ok) {
				cout << n - r << "\n";
				break;
			}
		}
	}
}

void ChessboardandQueens() {
	int queens[8]{ 0, 1, 2, 3, 4, 5, 6, 7 }, ans{};

	char arr[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> arr[i][j];

	do
	{
		set<int> diag1, diag2;

		for (int i = 0; i < 8; i++)
		{
			if (arr[i][queens[i]] == '*')
				break;
			diag1.insert(i + queens[i]);
			diag2.insert(i - queens[i]);
		}

		if (diag1.size() == 8 && diag2.size() == 8)
			ans++;
	} while (next_permutation(queens, queens + 8));

	cout << ans;
}

int N, M;
struct cow { int s, t, c; };
vector<cow> cows;
struct air { int a, b, p, m; };
vector<air> air_conditioners;
int min_cost = 1e4 + 1;
void minimum(vector<bool>& uses) {
	bool is_feasible = true;

	// iterate through all positions to check if the current subset is feasible
	for (int i = 1; i <= 100; i++)
	{
		// iterate through air conditioners to find the current cooling units
		int cooling = 0;
		for (int j = 0; j < M; j++)
		{
			if (uses[j])
			{
				auto& [a, b, p, m] = air_conditioners[j];
				// check if i is in the range
				if (i >= a && i <= b)
					cooling += p;
			}
		}

		// iterate through cows to find the current cow requirement
		int cow_requirement = 0;
		for (int j = 0; j < N; j++)
		{
			auto& [s, t, c] = cows[j];
			if (i >= s && i <= t) {
				cow_requirement = c;
				break;
			}
		}

		// For each position, the requirement of the cow must be met
		if (cow_requirement > cooling) {
			is_feasible = false;
			break;
		}
	}

	if (is_feasible)
	{
		int cost{};
		for (int i = 0; i < M; i++) {
			if (uses[i])
				cost += air_conditioners[i].m;
		}
		min_cost = min(min_cost, cost);
	}
}
void search(vector<bool>& uses, int i = 0) {
	if (i == M)
		return minimum(uses);

	// generate subset https://www.youtube.com/watch?v=REOH22Xwdkk
	uses[i] = false;
	search(uses, i + 1);
	uses[i] = true;
	search(uses, i + 1);

}
void AirCownditioningII() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		cows.push_back({ s, t, c });
	}

	for (int i = 0; i < M; i++) {
		int a, b, p, m;
		cin >> a >> b >> p >> m;
		air_conditioners.push_back({ a, b, p, m });
	}

	// uses[i] == true: the i-th air conditioner is used
	vector<bool> uses(M, false);

	search(uses);

	cout << min_cost;
}

void LivestockLineup() {
	fstream in("lineup.in");
	ofstream out("lineup.out");

	int n;
	in >> n;

	vector<pair<string, string>> vec;
	for (int i = 0; i < n; i++) {
		string s0, temp, s5;
		in >> s0 >> temp >> temp >> temp >> temp >> s5;

		vec.push_back({ s0, s5 });
	}

	string names[]{ "Beatrice","Sue","Belinda","Bessie","Betsy","Blue","Bella","Buttercup" };
	sort(names, names + 8);

	while (next_permutation(names, names + 8)) {
		bool passed = true;
		for (const auto& [cow1, cow2] : vec)
		{
			auto a = find(names, names + 8, cow1);
			auto b = find(names, names + 8, cow2);

			if (abs(a - b) != 1) {
				passed = false;
				break;
			}
		}
		if (passed)
			break;
	}

	for (int i = 0; i < 8; i++)
		out << names[i] << "\n";
}

void BackandForth() {
	ifstream in("backforth.in");
	ofstream out("backforth.out");

	vector<int> A(10), B(10);
	for (int i = 0; i < 10; i++) cin >> A[i];
	for (int i = 0; i < 10; i++) cin >> B[i];

	int a, b, c, d;
	set<int> set;
	set.insert(1000);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			set.insert(1000 - A[i] + B[j]);
			a = A[i], b = B[j];
			for (int k = i + 1; k < 10; k++) {
				for (int l = j + 1; l < 10; l++) {
					set.insert(1000 - A[i] + B[j] - A[k] + B[l]);
					a = A[i], b = B[j], c = A[k], d = B[l];
				}
			}
		}
	}

	cout << set.size();
}

int main()
{
	BackandForth();
}