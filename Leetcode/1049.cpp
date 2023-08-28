#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		int sum = 0;
		for (auto x : stones)
		{
			sum = sum + x;
		}
		int target = sum / 2;

		vector<int> dp(15001, 0);

		for (int i = 1; i < stones.size(); i++)
		{
			for (int j = target; j >= stones[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}

		return sum - dp[target] * 2;
	}
};