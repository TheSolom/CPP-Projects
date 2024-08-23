#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int freq[10]{};
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;

			freq[x % 10]++;
		}

		vector<int> nums;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < min(freq[i], 3); j++)
				nums.push_back(i);

		bool flag = false;
		for (int i = 0; i < nums.size(); i++)
			for (int j = i + 1; j < nums.size(); j++)
				for (int k = j + 1; k < nums.size(); k++)
					if ((nums[i] + nums[j] + nums[k]) % 10 == 3) {
						flag = true;
						break;
					}

		cout << (flag ? "YES\n" : "NO\n");
	}
}