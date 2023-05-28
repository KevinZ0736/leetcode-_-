#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, const vector<int>& nums) {
      /*  int head = 0; int tail = nums.size() - 1; int sum = 0;
        for (int val : nums) { sum = sum + val; }
        if (sum < target) { return 0; }
        while ((head < tail) && (sum > target))
        {
            if (nums[head] <= nums[tail]) {
                sum = sum - nums[head++];
            }
            else
            {
                sum = sum - nums[tail--];
            }
            cout << sum << endl;
        }
        if(sum < target)
        { return tail - head + 2; }
        else
        { return  tail - head + 1; }*/

        int head = 0; int tail = 0; int sum = 0; int len = nums.size();
        for (tail = 0; tail < nums.size(); tail++)
        {
            sum = sum + nums[tail];
            while (sum >= target)
            {
                len = min(len, tail - head + 1);
                sum = sum - nums[head++];
            }
           
        }
        return len; 
    }
};

int main()
{
    Solution s;
    int a = s.minSubArrayLen(80
    ,{10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8
});
    cout << a << endl;
}