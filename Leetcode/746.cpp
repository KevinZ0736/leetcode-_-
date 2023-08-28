#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>&& cost) {
		vector<int> sum(cost.size() + 2, 0);
		cost.insert(cost.begin(), 0);

		for (int i = 2; i < sum.size(); i++)
		{
			sum[i] = min(sum[i - 1] + cost[i - 1], sum[i - 2] + cost[i - 2]);
		}
		return sum[sum.size() - 1];
	}
};

int main()
{
	Solution s;
	cout << s.minCostClimbingStairs({ 10,15,20 });
}