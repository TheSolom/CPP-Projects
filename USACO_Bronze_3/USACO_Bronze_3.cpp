#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

void DistinctNumbers() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());

	int ans{ 1 };
	for (int i = 1; i < n; i++) {
		/*
		 * if the current number is different from the previous
		 * it is a distinct number so we add 1 to the answer
		 */
		ans += (vec[i] != vec[i - 1]);
	}
	cout << ans;
}

void PlayinginaCasino() {
	// https://www.youtube.com/watch?v=FCdL47-AyZs
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> vec(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> vec[i][j];

		long long ans{};
		for (int i = 0; i < m; i++)
		{
			vector<long long> coloumn;
			long long total{};
			for (int j = 0; j < n; j++) {
				coloumn.push_back(vec[j][i]);
				total += vec[j][i];
			}
			sort(coloumn.begin(), coloumn.end());
			/*
			* 1 3 7
			* prefix sum: 1 4 11
			* eq: 11 - 1 - (1*2)
			*/
			long long curr{};
			for (int j = 0; j < n; j++) {
				curr += coloumn[j];
				ans += llabs((total - curr) - (coloumn[j] * (n - 1 - j)));
			}
		}

		cout << ans << "\n";
	}
}

void Kayaking() {
	int n;
	cin >> n;

	vector<int> vec(n * 2);
	for (int i = 0; i < n * 2; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	int ans = INT32_MAX;
	// loop through all possible combinations of people in the single kayaks
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = i + 1; j < 2 * n; j++)
		{
			// vector 's' will store the weights of the people who need to be
			// placed in tandem kayaks
			vector<int> duo;
			for (int k = 0; k < 2 * n; k++)
				if (k != i && k != j)
					duo.push_back(vec[k]);

			int temp{};  // this variable stores the instability of this situation
			for (int k = 0; k < 2 * n - 2; k += 2)
				temp += duo[k + 1] - duo[k]; // calculating instability

			// if this instability is lower than our current answer, then update
			ans = min(ans, temp);
		}
	}
	cout << ans;
}

void CowCollege() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	sort(vec.begin(), vec.end());

	long long max_tuition{}, min_money{};
	for (int i = 0; i < n - 1; i++)
	{
		long long curr_tuition = (long long)vec[i] * (n - i);
		if (curr_tuition > max_tuition)
		{
			max_tuition = curr_tuition;
			min_money = vec[i];
		}
	}

	cout << max_tuition << " " << min_money;
}

void WhyDidtheCowCrosstheRoadIII() {
	ifstream in("cowqueue.in");
	ofstream out("cowqueue.out");

	int n;
	in >> n;

	vector<pair<int, int>> cows(n);
	for (int i = 0; i < n; i++)
		in >> cows[i].first >> cows[i].second;
	sort(cows.begin(), cows.end());

	int curr_time{};
	for (int i = 0; i < n; i++)
	{
		if (curr_time > cows[i].first)
			// this cow was already waiting, add duration to current time
			curr_time += cows[i].second;
		else
			// the last cow finished before this one arrived, so set the current time to when this cow finishes
			curr_time = cows[i].first + cows[i].second;
	}

	out << curr_time;
}

void SumofTwoValues() {
	int n, x;
	cin >> n >> x;

	vector<pair<int, int>> vec;
	// append the element and its index
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		vec.push_back({ num, i + 1 });
	}
	sort(vec.begin(), vec.end());

	int left = 0, right = n - 1;
	while (left < right) {
		// adjust left and right pointers
		if (vec[left].first + vec[right].first == x) {
			cout << vec[left].second << " " << vec[right].second;
			return;
		}
		else if (vec[left].first + vec[right].first > x) {
			right--;
		}
		else if (vec[left].first + vec[right].first < x) {
			left++;
		}
	}

	cout << "-1";
}

void WhereAmI() {
	ifstream in("whereami.in");
	ofstream out("whereami.out");

	int n;
	string s;
	in >> n >> s;

	for (int i = 1; i <= n; i++)
	{
		unordered_set<string> set;
		bool found = false;
		for (int j = 0; j < n; j++)
		{
			string range = s.substr(j, i);
			if (set.count(range) == 0)
				set.insert(range);
			else {
				found = true;
				break;
			}
		}

		if (!found) {
			out << i;
			break;
		}
	}
}

set<set<char>> Set[4];
void test(char a, char b, char c) {
	set<char> s;
	s.insert(a);
	s.insert(b);
	s.insert(c);

	Set[s.size()].insert(s);
}
void TeamTicTacToe()
{
	ifstream in("tttt.in");
	ofstream out("tttt.out");

	vector<vector<char>> vec(3, vector<char>(3));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			in >> vec[i][j];

	test(vec[0][0], vec[0][1], vec[0][2]); // Rows
	test(vec[1][0], vec[1][1], vec[1][2]);
	test(vec[2][0], vec[2][1], vec[2][2]);

	test(vec[0][0], vec[1][0], vec[2][0]); // Cols
	test(vec[0][1], vec[1][1], vec[2][1]);
	test(vec[0][2], vec[1][2], vec[2][2]);

	test(vec[0][0], vec[1][1], vec[2][2]); // -vec diag

	test(vec[2][0], vec[1][1], vec[0][2]); // +ve diag

	out << Set[1].size() << "\n" << Set[2].size();
}

string SORT(map<string, int>& mp)
{
	multimap<int, string> MM;

	for (auto& it : mp)
		MM.insert({ it.second, it.first });

	int min = (MM.size() == 7) ? MM.begin()->first : 0;
	string designated_cow;
	bool flag = false;
	for (const auto& it : MM)
	{
		if (!flag && it.first > min) {
			min = it.first;
			designated_cow = it.second;
			flag = true;
		}
		else if (flag && it.first == min)
			return "Tie";
	}

	return flag ? designated_cow : "Tie";
}
void DontBeLast() {
	ifstream in("notlast.in");
	ofstream out("notlast.out");

	int n;
	in >> n;

	map<string, int> mp;
	while (n--) {
		string s;
		int m;
		in >> s >> m;

		mp[s] += m;
	}

	out << SORT(mp) << "\n";
}

void YearoftheCow() {
	int n;
	cin >> n;

	const unordered_map<string, int> ZODIAC{
		{"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3},
		{"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7},
		{"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}
	};

	unordered_map<string, int> cows{ {"Bessie", 0} };

	for (int i = 0; i < n; i++) 
	{
		string c1, c2, dir, yr, t;
		cin >> c1 >> t >> t >> dir >> yr >> t >> t >> c2;

		int d, age = cows[c2];
		if (dir == "previous")
			d = -1;
		else if (dir == "next")
			d = 1;

		do {
			age += d;
		} while ((12 + age % 12) % 12 != ZODIAC.at(yr));

		cows[c1] = age;
	}

	cout << abs(cows["Elsie"]) << '\n';
}

void CitiesandStates() {
	// https://www.youtube.com/watch?v=eZoq_PBFERs
	ifstream in("citystate.in");
	ofstream out("citystate.out");

	int n;
	in >> n;

	unordered_map<string, int> mp;
	string city, state;
	int ans{};
	for (int i = 0; i < n; i++) 
	{
		in >> city >> state;
		city = city.substr(0, 2);

		if (city != state)
			mp[city + state]++;
		
		ans += mp[state + city];
	}

	out << ans;
}

int main()
{
	CitiesandStates();
}