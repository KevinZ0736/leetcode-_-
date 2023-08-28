#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>&& nums, int target) {
		int sum = 0;
		for (auto x : nums)
		{
			sum = sum + x;
		}

		if ((sum + target) % 2 != 0)
			return 0;
		int tar = (sum + target) / 2;

		vector<int> dp(tar + 1, 1);
		dp[0] = 1;

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = tar; j >= nums[i]; j--)
			{
				dp[j] = dp[j - nums[i]] + dp[j];
			}
		}
		return dp[tar];
	}
};

int main()
{
	Solution s;
	s.findTargetSumWays({ 1,1,1,1,1 }, 3);
}