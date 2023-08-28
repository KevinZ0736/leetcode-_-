#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>&& nums, int target) {
		sort(nums.begin(), nums.end());
		if (nums[0] > target)
			return 0;

		vector<int> dp(target + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= target; i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]])
				{
					dp[i] = dp[i] + dp[i - nums[j]];
				}
			}
		}

		return dp[target];
	}
};

int main()
{
	Solution s;
	cout << s.combinationSum4({ 1,2,3 }, 4);
}