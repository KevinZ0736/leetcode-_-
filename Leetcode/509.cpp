#include< iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0) return 1;

		if (n == 1) return 1;

		vector<int> sum(n + 1, 0);

		sum[0] = 1; sum[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			sum[i] = sum[i - 1] + sum[i - 2];
		}
		return sum[n];
	}
};

int main()
{
	Solution s;
	cout << s.climbStairs(45);
}