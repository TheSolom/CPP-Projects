#include <iostream>
using namespace std;

bool checklpYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool checkMonth(int m2, int m)
{
	return ((m2 == m) || ((((m2 - m) % 12 + 12) % 12) == 1));
}

bool checkDay(int d2, int d, int m2, int m, int y2 , int y)
{
	if (m == 2 && d2 == 1 && d == 28 && !checklpYear(y))
		return true;

	else if (m == 2 && d2 == 1 && d == 29)
		return true;

	else if (m2 == m && m == 2 && d2 - d == 1)
		return true;

	else if (((m == 4 && m2 == 5) || (m == 6 && m2 == 7) || (m == 9 && m2 == 10) || (m == 11 && m2 == 12)) && d2 == 1 && d == 30)
		return true;

	else if (m2 - m && d2 == 1 && d == 31)
		return true;

	else if (m2 == m && d2 - d == 1 && y2 == y)
		return true;
	
	return false;
}


int main()
{
    int n;
	while (cin >> n, n != 0)
	{
		int d, m, y, c, cnt = 0, sum = 0;
		cin >> d >> m >> y >> c;

		while (--n)
		{
			int d2, m2, y2, c2;
			cin >> d2 >> m2 >> y2 >> c2;

			if ((y2 == y || y2 - y == 1) && checkMonth(m2, m) && checkDay(d2, d, m2, m, y2, y))
			{
				cnt++;
				sum += c2 - c;
			}

			d = d2, m = m2, y = y2, c = c2;
		}

		cout << cnt << " " << sum << endl;
	}
}