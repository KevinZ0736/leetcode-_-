#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>&& coins, int amount) {
		sort(coins.begin(), coins.end());

		if (coins[0] > amount)
		{
			return -1;
		}
		vector<int> dp(amount + 1, INT_MAX-1);
		dp[0] = 0;

		for (int i = 0; i < coins.size(); i++)
		{
			for (int j = coins[i]; j <= amount; j++)
			{
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		if (dp[amount] == INT_MAX - 1)
			return -1;
		return dp[amount];
	}
};

int main()
{
	Solution s;
	s.coinChange({ 2 }, 3);
}