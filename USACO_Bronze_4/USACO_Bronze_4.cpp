#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void SleepyCowHerding() {
	ifstream in("herding.in");
	ofstream out("herding.out");

	int a, b, c;
	in >> a >> b >> c;

	int l = abs(b - a - 1), r = abs(c - b - 1);

	if (l == 0 || r == 0)
		out << "0" << '\n';
	else if (l == 1 || r == 1)
		out << "1" << '\n';
	else
		out << "2" << '\n';

	out << max(l, r);
}

void MadScientist() {
	ifstream in("breedflip.in");
	ofstream out("breedflip.out");

	int n;
	string a, b;
	in >> n >> a >> b;

	int ans{};
	for (int i = 0; i < n; i++)
		if (a[i] != b[i] && a[i + 1] == b[i + 1])
			ans++;

	out << ans << "\n";
}

void CowTipping() {
	ifstream in("cowtip.in");
	ofstream out("cowtip.out");

	int n;
	in >> n;

	vector<vector<char>> farm(n, vector<char>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> farm[i][j];

	int totalflips{};
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			// go from bottom right to top, check if it's a 1
			if (farm[i][j] == '1')
			{
				totalflips++;
				// flip cows rectangle until (i, j) point
				for (int a = 0; a <= i; a++)
					for (int b = 0; b <= j; b++)
						farm[a][b] = farm[a][b] == '1' ? '0' : '1';
				// end cow flip
			}
		}
	}

	out << totalflips;
}

void EvenMoreOddPhotos() {
	/*	
		even	odd
		0		7
		1		5
		2		3
		3		1
		even = odd + 1
		2		1
		= eoe  3

		even	odd
		1		6
		2		4
		even = odd + 1
		3		2
		= eoeoe 5
	*/
	int n;
	cin >> n;

	int even{}, odd{};
	for (int i = 0; i < n; i++) 
	{
		int cow;
		cin >> cow;

		if (cow % 2 == 0)
			even++;
		else 
			odd++;
	}

	// Pair up odd cows so that there aren't too many of them.
	while (odd > even) {
		odd -= 2;
		// Two odd cows together are effectively an even cow.
		even++;
	}
	// Group even cows so that there aren't too many evens either.
	if (even > odd + 1)
		even = odd + 1;

	cout << odd + even << endl;
}

int main()
{
	EvenMoreOddPhotos();
}