#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_2 {
public:
	int binarySearch(vector<vector<int>>& vec, int target) {
		int low = 0, high = (int)vec.size() - 1;

		if (vec[low][0] > vec[high][0])
			swap(low, high);

		int ans = -1;
		if (low < high)
		{
			while (low <= high) {
				int mid = low + (high - low) / 2;

				if (vec[mid][0] == target)
					return mid;
				if (vec[mid][0] < target)
					low = mid + 1;
				else {
					ans = mid;
					high = mid - 1;
				}
			}

			return ans;
		}
		else
		{
			while (low >= high) {
				int mid = high + (low - high) / 2;

				if (vec[mid][0] == target)
					return mid;
				if (vec[mid][0] < target)
					low = mid - 1;
				else {
					ans = mid;
					high = mid + 1;
				}
			}

			return ans;
		}
	}

	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		vector<int> ans;
		for (int i = 0; i < intervals.size(); i++)
			ans.push_back(binarySearch(intervals, intervals[i][1]));

		return ans;
	}
};

class Solution_3 {
public:
	int triangleNumber(vector<int>& nums) {	// O(n^2) time
		int count = 0, n = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 2; i++) {
			int k = i + 2;	// observe k shared between js
			// k: the first invalid index: c >= a+b
			// We don't need to keep compute it for each j
			// Last j found its k. We can that keep pushing it
			// as anyway positions < k are valid
			for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
				while (k < n && nums[i] + nums[j] > nums[k])
					++k;
				count += k - j - 1;
			}
		}
		return count;
	}
	// We can also rewrite in a difference way: https://leetcode.com/problems/valid-triangle-number/discuss/104177/O(N2)-solution-for-C%2B%2B-and-Python
};

int main()
{
	vector<int> v{ 2,2,3,4 };
	Solution_3 ss;
	cout << ss.triangleNumber(v);
}