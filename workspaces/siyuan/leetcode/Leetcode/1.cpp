#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        vector<int> a;
        unordered_map<int, int> map;
        
        for (int m = 0; m < nums.size(); m++)
        {
            auto an = map.find(target - nums[m]);
            cout << m; //<< " " << an->second << endl;
            if (an != map.end())
            {
                a.emplace_back(an->second);
                a.emplace_back(m);
                return a;
            }
            map.insert(pair<int, int>(nums[m], m));
        }
        return a;
    }
};

int main()
{
    Solution s;
    auto a = s.twoSum({3,2,4}, 6);
    for (int val : a) { cout << val <<" "; }
//    std::printf("a");
}

