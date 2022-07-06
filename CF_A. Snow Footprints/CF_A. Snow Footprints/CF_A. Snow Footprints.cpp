#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	//determine first and last positions
	int fst = 0;
	int lst = 0;

	//Find first non . character
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != '.')
		{
			fst = i + 1;
			break;
		}
	}
	//Find last non . character
	for (int i = n - 1; i >= 0; --i)
	{
		if (s[i] != '.')
		{
			lst = i + 1;
			break;
		}
	}

	//we have 3 cases: RRRRRRRRRR, LLLLLLLLLL, RRRRRRRRLLLLLL

	if (s[fst - 1] == 'R' && s[lst - 1] == 'R')
		cout << fst << " " << lst + 1 << endl;	// +1 for position shifting

	else

		if (s[fst - 1] == 'L' && s[lst - 1] == 'L')
			cout << lst << " " << fst - 1 << endl;

	else 
	if (s[fst - 1] == 'R' && s[lst - 1] == 'L')
	{
				//Find the position of flip from R to L
		int i;
		for (i = fst - 1; i < n; ++i)
		{
			if (s[i] == 'L')
				break;
		}

		cout << fst << " " << i + 1 - 1 << endl;
	}

}