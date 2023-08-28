#include <iostream>
#include <vector>

using namespace std;

// 细化成每天的收益，只要一直保持正收益，局部最大退出全局最大

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int> cost(prices.size(), 0);

		for (int i = 1; i < cost.size(); i++)
		{
			cost[i] = prices[i] - prices[i - 1];
		}

		int sum = 0;

		for (int i = 1; i < cost.size(); i++)
		{
			if (cost[i] > 0)
				sum = sum + cost[i];
		}

		return sum;
	}
};