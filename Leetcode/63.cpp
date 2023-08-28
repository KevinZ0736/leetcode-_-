#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//	int uniquePathsWithObstacles(vector<vector<int>>&& obstacleGrid) {
//
//		vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
//		for (int i = 0; i < dp[0].size(); i++)
//		{
//			if (obstacleGrid[0][i] == 1)
//				break;
//			dp[0][i] = 1;
//		}
//
//		for (int i = 0; i < dp.size(); i++)
//		{
//			if (obstacleGrid[i][0] == 1)
//				break;
//			dp[i][0] = 1;
//		}
//
//		if (obstacleGrid.size() <= 1 || obstacleGrid[0].size() <= 1)
//			return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
//
//		for (int i = 1; i < dp.size(); i++)
//		{
//			for (int j = 1; j < dp.size(); j++)
//			{
//				if ((obstacleGrid[i][j] == 1) || (obstacleGrid[i - 1][j] == 1 && obstacleGrid[i][j - 1] == 1))
//				{
//					dp[i][j] == 0;
//					continue;
//				}
//				if (obstacleGrid[i - 1][j] == 1)
//				{
//					dp[i][j] = dp[i][j - 1];
//					continue;
//				}
//				if (obstacleGrid[i][j - 1] == 1)
//				{
//					dp[i][j] = dp[i - 1][j];
//					continue;
//				}
//				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//
//			}
//		}
//
//		return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
//	}
//};

class Solution {

public:
	int uniquePathsWithObstacles(vector<vector<int>>&& obstacleGrid) {
		int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
		vector<int> f(m);

		if (obstacleGrid[0][0] == 1) f[0] = 0;
		else f[0] = 1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (obstacleGrid[i][j] == 1) {
					f[j] = 0;
					continue;
				}

				if (j > 1 && obstacleGrid[i][j - 1] == 0)
					f[j] = f[j - 1] + f[j];
				else
				{
					f[j] = f[j];
				}
			}
		}

		return *(f.end() - 1);
	}
};

int main()
{
	Solution s;
	cout << s.uniquePathsWithObstacles({ {0,0 }, { 1,1 }, { 0,0 } });
}