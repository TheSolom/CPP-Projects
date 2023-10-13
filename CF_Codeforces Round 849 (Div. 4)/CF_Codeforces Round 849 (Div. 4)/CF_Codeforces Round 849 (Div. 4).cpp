#include <iostream>
using namespace std;
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> n >> s;
		
		if (n == 0)  
			cout << 0 << endl;
		else if (n==1) 
			cout << 1 << endl; 
		else if (n==2)
		{
			if (s[0] != s[1]) 
				cout << 0 << endl;
			else
				cout << 2 << endl;
		}
		else
		{
			if (n % 2) //odd
			{
				int i = n / 2 - 1, j = n / 2 + 1;
				bool flag = false;
				if (s[i] == s[j])
				{
					while (--i > -1 && ++j < n)
					{
						if (s[i] != s[j])
						{
							cout << j - i - 2<< endl;
							flag = true;
							break;
						}
					}
					if (!flag) cout << n << endl;
				}
				else cout << 1 << endl;
			}
			else
			{
				int flag = 0, step{};
				int i = n / 2 - 1, j = n / 2;
				
				while (i > -1 && j < n)
				{
					if (s[i] == s[j])
					{
						if (s[--i] != s[++j])
						{
							flag = 1;
							break;
						}
					}
					else
					{
						if ((--i > -1 && ++j < n) && (s[i] != s[j]))
						{
							step++;
						}
						else
						flag++;
					}
				}
				if (step == n / 2 - 1) cout << 0 << endl;
				else if (flag == 1) { cout << j - i - 1 << endl; }
				else
					cout << j - i - 2 << endl;
			}
		}
	}
}