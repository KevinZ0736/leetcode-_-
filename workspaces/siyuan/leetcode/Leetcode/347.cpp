#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n)
    {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occ;
        for (int x : nums)
        {
            occ[x]++;
        }
        priority_queue<pair<int, int>, decltype(&cmp)> q;
        for (auto i =occ.begin();i!=occ.end();i++)
        {
            if (q.size() == k)
            {
                if (q.top().second < (*i).second)
                {
                    q.pop();
                        q.emplace((*i).first, (*i).second);
                }
            }
            else {
                q.emplace((*i).first, (*i).second);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;

    }

};