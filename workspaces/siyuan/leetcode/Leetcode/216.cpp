#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sum = 0;
    void combine(vector<vector<int>> &result,vector<int> &r,int k,int n,int index)
    {
      
        if (r.size() == k)
        {
            if (sum == n) { result.push_back(r); }
            else { return; }
        }
        else if (r.size() < k)
        {
            for (int i = index; (i <= n - sum) && (r.size() <= k - 1) && (i <= r.size() - k + 1 + n); i++)
            {
                sum = sum + i;
                r.push_back(i);
                combine(result, r, k, n, i + 1);
                sum = sum - i;
                r.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> r;
        combine(result, r, k, n, 1);
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.combinationSum3(2, 18).size();
}