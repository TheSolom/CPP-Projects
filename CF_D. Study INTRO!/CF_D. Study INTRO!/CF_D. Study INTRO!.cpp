#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<string> st;
	string s; 
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == "Header")
		{
			if (i == 0)
				flag = true;
			else
				flag = false;
		}

		if (!st.empty() && st.top() == s.substr(3))
			st.pop();
		else
			st.push(s);
	}

	if (st.empty() && flag)
		cout << "ACC\n";
	else
		cout << "WA\n";
}