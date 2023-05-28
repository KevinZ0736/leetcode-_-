#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class Solution {
public:
    
    
    void pop(deque<int> &que)
    {
        if(!que.empty())
        {
            que.pop_back();
        }
       
    }

    void push(deque<int>& que, int x,int k)
    {
        while ((!que.empty()) && x > que.front())
        {
            que.pop_front();
        }
        if (que.size() <= k)
        {
            que.push_front(x);
        }
    }

    int getMax(deque<int>& que)
    {
        return que.back();
    }

    vector<int> maxSlidingWindow(vector<int>&& nums, int k) {
        vector<int> result;
        deque<int> que;
        if (nums.size()) { result.emplace_back(max(nums.begin(),nums.end())); }
        for (int i = 0; i < nums.size(); i++)
        {
            push(que, nums[i], k);
            if (i >= )
            {
                result.emplace_back(getMax(que));
                if (nums[i - 2] == que.back())
                {
                    pop(que);
                }
            }
            
        }
        return  result;
    }
};

int main()
{
    Solution s;
    vector<int> a =s.maxSlidingWindow({ 1,3,-1,-3,5,3,6,7 },3);
    for (int x : a) { cout << x; }
    
}