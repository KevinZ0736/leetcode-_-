#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
	vector<vector<int>> result;
	int flag = 0;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> used(nums.size(), 0);
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		get(nums, used, tmp, 0);
		return result;
	}

	void get(vector<int>& nums, vector<int>& used, vector<int>& tmp, int index)
	{
		if (tmp.size() < nums.size())
		{
			for (int i = index; i < nums.size(); i++)
			{
				if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == 0)
				{
					continue;
				}
				else if (used[i] == 1) {
					continue;
				}

				tmp.emplace_back(nums[i]);
				used[i] = 1;
				get(nums, used, tmp, 0);
				tmp.pop_back();
				used[i] = 0;

			}
			return;
		}
		else {
			result.emplace_back(tmp);
			return;
		}
	}


};