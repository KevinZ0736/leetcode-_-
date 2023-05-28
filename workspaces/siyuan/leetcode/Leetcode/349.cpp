#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m;
        if (nums1.size() >= nums2.size())
        {
            for (auto i : nums1) { m.emplace(i,0); }
            for (auto q : nums2)
            {
                if (m.find(q) != m.end() && (*m.find(q)).second == 0) { ans.emplace_back(q); (*m.find(q)).second++; }
            }
            return ans;
        }
        else
        {
            for (auto i : nums2) { m.emplace(i, 0); }
            for (auto q : nums1)
            {
                if (m.find(q) != m.end() && (*m.find(q)).second == 0) { ans.emplace_back(q); (*m.find(q)).second++; }
            }

            return ans;
        }
    }
        
};

