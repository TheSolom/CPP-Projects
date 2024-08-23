#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include<iomanip>
using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> sorted{ nums };
		sort(sorted.begin(), sorted.end());

		int left = -1, right = -1;
		for (int i = 0; i < (int)nums.size(); i++) {
			if (nums[i] != sorted[i]) {
				if (left == -1)
					left = i;
				else
					right = i;
			}
		}

		if (left == -1)
			left = 0;

		return right - left + 1;
	}

	int findUnsortedSubarrayV2(vector<int>& nums) {
		int max = INT_MIN, min = INT_MAX;
		int left = -1, right = -1;
		for (int i = 0; i < (int)nums.size(); i++) 
		{
			max = std::max(max, nums[i]);

			if (max > nums[i])
				right = i;
		}
		if (right == -1)
			return 0;

		for (int i = (int)nums.size() - 1; i >= 0; i--)
		{
			min = std::min(min, nums[i]);

			if (min < nums[i])
				left = i;
		}

		return right - left + 1;
	}

	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		vector<pair<int, int>> jobs;
		for (int i = 0; i < (int)difficulty.size(); i++)
			jobs.push_back({ difficulty[i], profit[i] });

		sort(jobs.begin(), jobs.end());
		sort(worker.begin(), worker.end());

		int max = 0, total_profit = 0;
		for (int i = 0, j = 0; i < worker.size(); i++)
		{
			for (; j < jobs.size() && worker[i] >= jobs[j].first; j++)
			{
				max = std::max(max, jobs[j].second);
			}

			total_profit += max;
		}

		return total_profit;
	}

	int reductionOperations(vector<int>& nums) {
		sort(nums.rbegin(), nums.rend());

		int cnt{};
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != nums[i - 1])
				cnt += i;
		}

		return cnt;
	}
};

double circle_area(double r) {
	const double PI = acos(-1.0);
	return PI * r * r;
}
double largest_area(vector<double>& pie_radius, int people) {
	
}

int main()
{
	int cases, n, f;
	cin >> cases;

	while (cases--) {
		cin >> n >> f;
		vector<double> pie_radius(n);

		for (int i = 0; i < n; i++)
			cin >> pie_radius[i];

		double area = largest_area(pie_radius, f + 1);	// +1 for the host person

		cout << fixed;
		cout << setprecision(4) << area << "\n";
	}
}