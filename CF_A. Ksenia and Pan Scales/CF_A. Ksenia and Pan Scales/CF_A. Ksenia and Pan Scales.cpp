#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    string str, ch, s1, s2;
    cin >> str >> ch;
	s1 = str.substr(0, str.find("|"));
	s2 = str.substr(str.find("|") + 1);

	ll cntr = 0, ch_size = ch.length();

	while (ch_size != 0)
	{
		if (s1.length() > s2.length())
		{
			s2 += ch[cntr++];
			ch_size--;		
		}
		else if (s2.length() >= s1.length())
		{
			s1 += ch[cntr++];
			ch_size--;
		}
	}

	if (s1.length() == s2.length())
		cout << s1 << "|" << s2;
	else
		cout << "Impossible";
		
}