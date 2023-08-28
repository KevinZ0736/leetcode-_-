#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool canPartition(vector<int>&& nums) {
		if (nums.size() == 1)
			return false;
		int sum = 0;
		for (auto x : nums)
		{
			sum += x;
		}
		if (sum % 2 != 0)
			return false;
		sum = sum / 2;
		vector<int> dp(sum + 1, 0);

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = sum; j >= nums[i]; j--)
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		}

		if (dp[sum] == sum)
			return true;
	}
};

int main()
{
	Solution s;
	s.canPartition({ 1,5,11,5 });
}