#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> st;
	int cnt{};
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			st.push('(');
		}
		else if (!st.empty()) //s[i] == ')'
		{
			st.pop();
			cnt += 2;
		}
	}

	cout << cnt << "\n";
}