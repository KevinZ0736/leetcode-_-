#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int target, vector<int>&& nums) {
		int head = 0; int end = head; int sum = 0;
		int tar = 10001;
		while (head <= nums.size() - 1)
		{
			while (end <= nums.size() - 1 && sum < target)
			{
				sum = sum + nums[end];
				end++;
			}
			if (sum >= target) tar = min(tar, end - head);
			else if (end == nums.size() - 1 && sum <= target) break;
			sum = sum - nums[head];
			head++;
		}
		return tar;
	}
};

int main()
{
	Solution s;
	s.minSubArrayLen(7, vector<int>{2, 3, 1, 2, 4, 3});
}