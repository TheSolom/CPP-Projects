#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n; 
	cin >> n;

	queue<int> q; 
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a == 1)
		{
			q.push(b);
		}
		else
		{
			if (b == q.front())
				cout << "Yes\n";
			else
				cout << "No\n";
			q.pop();
		}
	}
}