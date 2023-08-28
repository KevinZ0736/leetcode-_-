#include <iostream>
#include <vector>
using namespace std;

class Solution {
	vector<vector<int>> result;
	int flag = 0;
public:
	void get(vector<int>& nums, vector<int>& used, vector<int>& tmp, int index)
	{
		if (flag < nums.size())
		{
			for (int i = 0; i < nums.size(); i++)
			{
				if (used[i] == 0)
				{
					tmp.emplace_back(nums[i]);
					used[i] = 1;
					flag++;
					get(nums, used, tmp, 0);
					tmp.pop_back();
					used[i] = 0;
					flag--;
				}
			}
			return;
		}
		else {
			result.emplace_back(tmp);
			return;
		}
	}

	vector<vector<int>> permute(vector<int> nums) {
		vector<int> used(nums.size(), 0);
		vector<int> tmp;
		get(nums, used, tmp, 0);
		return result;
	}
};