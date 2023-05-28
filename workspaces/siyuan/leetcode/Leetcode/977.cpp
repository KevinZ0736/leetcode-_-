#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(const vector<int>& nums) {
        vector<int> result;
        int i = 0; int negative = -1;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                negative = i;
            }
            else {
                break;
            }
        }
       
            int  j = negative + 1; i = negative;
            int i_key, j_key;
            while ((i >= 0) || (j < nums.size()))
            {
                cout << i << " " << j<<endl;
                if (i < 0) {
                    result.emplace_back(nums[j] * nums[j]);
                    ++j;
                }
                else if (j == nums.size()) {
                    result.emplace_back(nums[i] * nums[i]);
                    --i;
                }
                else {
                    i_key = nums[i] * nums[i];
                    j_key = nums[j] * nums[j];
                    result.emplace_back(min(i_key, j_key));
                    i_key <= j_key ? (i--) : (j++);
                }
            }
            return result;
    }
};

int main()
{
    Solution s;
    auto a = s.sortedSquares({ -5,-2,1,3,3,7 });
    for(int val:a)
    {
        cout << val << " ";
    }
}