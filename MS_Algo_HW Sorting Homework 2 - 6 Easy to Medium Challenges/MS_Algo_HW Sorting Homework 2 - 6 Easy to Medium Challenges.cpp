#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		sort(arr.begin(), arr.end());

		int min_diff = 1e6 + 1;
		for (int i = 1; i < arr.size(); i++)
		{
			int diff = arr[i] - arr[i - 1];
			if (diff < min_diff)
				min_diff = diff;
		}

		vector<vector<int>> ans;
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i] - arr[i - 1] == min_diff)
				ans.emplace_back(vector<int>{ arr[i - 1], arr[i] });
		}

		return ans;
	}

	int largestPerimeter(vector<int>& nums) {
		sort(nums.rbegin(), nums.rend());	// large to small

		for (int i = 0; i < (int)nums.size() - 2; i++)
		{
			if (nums[i + 2] + nums[i + 1] > nums[i])
				return nums[i + 2] + nums[i + 1] + nums[i];
		}
		return 0;
	}

	int largestSumAfterKNegations(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());

		int min{ 101 }, sum{};
		for (int i = 0; i < nums.size(); i++)
		{
			if (k && nums[i] < 0)
				nums[i] *= -1, k--;

			min = std::min(min, nums[i]);
			sum += nums[i];
		}
		if (k % 2)
			sum -= min * 2;

		return sum;
	}

	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		vector<int> time;
		for (int i = 0; i < dist.size(); i++) {
			if (dist[i] % speed[i] == 0)
				time.push_back(dist[i] / speed[i]);
			else
				time.push_back(dist[i] / speed[i] + 1);
		}

		sort(time.begin(), time.end());

		int ans{};
		for (int i = 0; i < dist.size() && i < time[i]; i++)
			ans++;

		return ans;
	}
};

int main()
{
	vector<int> vec{ 2,-3,-1,5,-4 };
	Solution ss;
	cout << ss.largestSumAfterKNegations(vec, 2);
}