#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>&& strs, int m, int n) {
		int tarm = 0; int tarn = 0; int flag = 0;
		for (auto x : strs)
		{
			tarm = getnum(x, '0');
			tarn = getnum(x, '1');
			if (tarm <= m && tarn <= n) { flag = 1; break; }
		}
		if (!flag)
			return 0;
		if (strs.size() == 1)
			return 1;

		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < strs.size(); i++)
		{
			tarm = getnum(strs[i], '0');
			tarn = getnum(strs[i], '1');
			for (int p = m; p >= tarm; p--)
			{
				for (int q = n; q >= tarn; q--)
				{
					dp[p][q] = max(dp[p - tarm][q - tarn] + 1, dp[p][q]);
				}
			}
		}
		return dp[m][n];

	}

	int getnum(string& str, const char& a)
	{
		int n = 0;
		for (auto x : str)
		{
			if (x == a)
				n++;
		}
		return n;
	}
};

int main()
{
	Solution s;
	cout << s.findMaxForm({ "10","0001","111001","1","0" }, 5, 3);
}