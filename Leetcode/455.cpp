#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int goal = 0;
        if (!s.size() || !g.size())  return goal;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        auto st = s.end() - 1;
        for (auto gi = g.end()-1; gi >= g.begin(); gi--)
        {
            for (auto si = st; si >= s.begin(); si--)
            {
                if (*gi <= *si)
                {
                    goal++;
                    st--;
                    break;
                }
            }
        }
        return goal;
    }
};