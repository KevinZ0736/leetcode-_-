#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		int min = INT_MAX;
		int gap = k;
		int sum = 0;
		while (gap > 0)
		{
			int tag = 0;
			min = INT_MAX;
			for (int j = 0; j < nums.size(); j++)
			{
				if (nums[j] < min)
				{
					min = nums[j];
					tag = j;
				}
				if (tag == 1)
					sum = sum + nums[j];
			}

			gap--;
			nums[tag] = -nums[tag];
		}
		sum = sum + (-2) * min;
		return sum;
	}
};