#include <iostream>
#include <vector>
using namespace std;

// dp[i]=sum(dp[i],dp[i-j]+dp[j])

class Solution {
public:
	int numTrees(int n) {
		if (n <= 3)
		{
			vector<int> dp(4, 0);
			dp[0] = 0; dp[1] = 1; dp[2] = 3; dp[3] = 5;
			return dp[n];
		}
		vector<int> dp(n + 1, 0);
		dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5;

		for (int i = 4; i <= n; i++)
		{

			for (int head = 0, end = i - 1 - head; head <= end; head++, end--)
			{
				if (head != end)
				{
					dp[i] = dp[head] * dp[end] * 2 + dp[i];
				}
				else {
					dp[i] = dp[head] * dp[end] + dp[i];
				}

			}
		}


		return dp[n];

	}
};

int main()
{
	Solution s;
	cout << s.numTrees(1);
}