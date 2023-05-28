#include<iostream>

#include<vector>
#include <iterator>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) { return result; }
        sort(nums.begin(), nums.end());
        int start, end, sum;
        for (int i = 0; i < nums.size() - 2;)
        {
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) { break; }
            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0)
            {
                do { i++; } while (nums[i] == nums[i - 1] && i < nums.size() - 2);
                continue;
            }
            start = i + 1; end = nums.size() - 1;
            while (start < end)
            {
                sum = nums[i] + nums[start] + nums[end];
                if (sum > 0)
                {
                    do { end--; } while (nums[end] == nums[end + 1] && start < end);
                }
                else if (sum < 0)
                {
                    do { start++; } while (nums[start] == nums[start - 1] && start < end);
                }
                else if (sum == 0)
                {
                    result.emplace_back(vector<int>{ nums[i], nums[start], nums[end] });
                    do { end--; } while (nums[end] == nums[end + 1] && start < end);
                    do { start++; } while (nums[start] == nums[start - 1] && start < end);
                }
            }
            do { i++; } while (nums[i] == nums[i - 1] && i < nums.size() - 2);
        }
        return result;
    }
};

int main()
{
    vector<int> a = {-1,0,1,2,1,-4,-3,-2,0,3,4,7,4,-5,-10};
    Solution s;
    auto r = s.threeSum(a);
    cout << r.size() << endl;
}