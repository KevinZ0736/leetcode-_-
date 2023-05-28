#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        vector<int> dp(cost.size()+1,0);
        dp[0] = 0;
        dp[1] = 0;
    
        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            cout << dp[i] << endl;
        }
        return dp[cost.size()];
    }
};

int main()
{
    Solution s;
    int i = s.minCostClimbingStairs({ 10, 15, 20 });
    cout << i;
}