#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void cal(vector<vector<int>> &result,vector<int> &re,int n, int k, int index)
    {
        //条件出口
        if (re.size() == k)
        {
            result.emplace_back(re);
            return;
        }
        for (int i = index; i<=n-(k-re.size())+1; i++)
        {
            re.emplace_back(i);
            cal(result, re, n, k, i+1);
            re.pop_back(); 
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> re;
        cal(result, re, n, k, 1);
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.combine(4, 4).size() << endl;

}