#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution { // Log(M) time complexity, where M is the maximum value in the array
public:
	bool is_sum_smaller(vector<int>& nums, int div, int threshold) {
		long long sum{};
		for (int i = 0; i < (int)nums.size(); i++)
			sum += (nums[i] + div - 1) / div;

		return sum <= threshold;
	}

	int smallestDivisor(vector<int>& nums, int threshold) {
		sort(nums.begin(), nums.end());

		int start = 1, end = nums[(int)nums.size() - 1];

		int ans = -1;
		while (start <= end) {
			int mid = start + (end - start) / 2;

			if (is_sum_smaller(nums, mid, threshold))
				end = mid - 1, ans = mid;
			else
				start = mid + 1;
		}

		return ans;
	}
};

class Solution_3 {
public:
	bool is_sum_smaller(vector<int>& nums, int div, int threshold) {
		long long sum{};
		for (int i = 0; i < (int)nums.size(); i++)
			sum += (nums[i] + div - 1) / div;

		return sum <= threshold;
	}

	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(nums.begin(), nums.end());

		int start = 1, end = nums[(int)nums.size() - 1];

		int ans = -1;
		while (start <= end) {
			int mid = start + (end - start) / 2;

			if (is_sum_smaller(nums, mid, threshold))
				end = mid - 1, ans = mid;
			else
				start = mid + 1;
		}

		return ans;
	}
};

int main()
{
	vector<int> v{ 44,22,33,11,1 };
	Solution ss;
	cout << ss.smallestDivisor(v, 5);
}