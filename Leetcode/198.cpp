﻿#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>&& nums) {
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);

		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}

		return *(dp.end() - 1);
	}
};

int main()
{
	Solution s;
	s.rob({ 1,2,3 });
}