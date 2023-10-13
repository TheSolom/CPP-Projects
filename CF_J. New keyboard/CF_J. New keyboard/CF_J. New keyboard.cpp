#include <iostream>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		string str = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '[')
			{
				while (s[i] != ']')
				{
					if (s[i] != '[')
						str += s[i];
					s.erase(i, 1);
				}
			}
			if (s[i] == ']')
			{
				while (s[i] != '[')
				{
					if (s[i] != ']')
						s += s[i];
					s.erase(i, 1);
				}
				--i;
			}
		}
		cout << str << s << "\n";
	}
}