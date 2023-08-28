#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>&& nums) {
		if (!nums.size())
			return 0;
		else if (nums.size() == 1)
			return 1;

		int tmp; int goal = 1; int end = nums.size() - 1; int head = end - 1;

		while (head >= 0 && nums[end] == nums[head])
		{
			head--;

		}
		if (head >= 0) { tmp = nums[end] - nums[head]; goal++; head--; end--; }
		while (head >= 0)
		{
			while (head >= 0 && nums[end] == nums[head])
			{
				head--;
			}
			if (head >= 0 && (tmp * (nums[end] - nums[head]) < 0))
			{
				goal++;
			}
			if (head >= 0)
			{
				tmp = nums[end] - nums[head];
				end = head;
				head--;
			}
		}

		return goal;
	}
};

int main()
{
	Solution s;
	cout << s.wiggleMaxLength(vector<int>{3, 3, 3, 2, 5});
}