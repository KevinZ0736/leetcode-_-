#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 串成环的意思就是 选了头不能选尾，选了尾不能选头
class Solution {
public:
	int rob(vector<int>&& nums) {
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		return max(parrob(vector<int>(nums.begin(), nums.end() - 1)), parrob(vector<int>(nums.begin() + 1, nums.end())));
	}

	int parrob(vector<int> nums) {
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		nums[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			nums[i] = max(nums[i - 2] + nums[i], nums[i - 1]);
		}

		return *(nums.end() - 1);
	}

};

int main()
{
	Solution s;
	s.rob({ 1,2,3,1 });
}