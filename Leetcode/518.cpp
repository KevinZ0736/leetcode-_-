#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int change(int amount, vector<int>&& coins) {
		sort(coins.begin(), coins.end());
		if (coins[0] > amount)
		{
			return 0;
		}

		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); i++)
		{
			for (int j = coins[i]; j <= amount; j++)
			{
				dp[j] = dp[j] + dp[j - coins[i]];
			}
		}
		return dp[amount];
	}
};

int main()
{
	Solution s;
	cout << s.change(5, { 1,2,5 });
}