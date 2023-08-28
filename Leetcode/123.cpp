#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 1)return 0;
		bool flag = false;
		for (int i = 1; i < prices.size(); i++)
		{
			if (prices[i] > prices[i - 1])
			{
				flag = true;
				break;
			}
		}
		if (!flag) return 0;
		vector<int> dp(4, 0);
		dp[0] = -prices[0]; dp[1] = 0;
		dp[2] = -prices[0]; dp[3] = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			dp[0] = max(dp[0], -prices[i]);
			dp[1] = max(dp[1], dp[0] + prices[i]);
			dp[2] = max(dp[2], dp[1] - prices[i]); // 在i时买与不买
			dp[3] = max(dp[3], dp[2] + prices[i]);

		}
		return max(dp[1], dp[3]);
	}
};