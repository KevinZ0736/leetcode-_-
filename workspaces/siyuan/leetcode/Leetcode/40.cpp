#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int sum = 0;

	void combine(vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp, vector<int>& used, int target, int index)
	{

		if (sum == target)
		{
			result.emplace_back(temp);
			return;
		}
		else if (sum > target)
		{
			return;
		}
		else if (sum < target)
		{
			for (int i = index; i < candidates.size() && sum + candidates[i] <= target ; i++)
			{

				if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == 0)
				{
					continue;
				}
				sum = sum + candidates[i];
				temp.emplace_back(candidates[i]);
				used[i] = 1;
				combine(candidates, result, temp, used, target, i + 1);
				temp.pop_back();
				sum = sum - candidates[i];
				used[i] = 0;
			}
		}

	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> temp;
		vector<vector<int>> result;
		vector<int> used(candidates.size(), 0);
		sort(candidates.begin(), candidates.end());
		combine(candidates, result, temp, used, target, 0);
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> can = { 1 };
	cout << s.combinationSum2(can, 1).size();
}