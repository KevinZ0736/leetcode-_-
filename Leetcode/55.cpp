#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>&& nums) {
		int cost = nums[0];
		int pos = 0;
		while (cost > 0 && pos < nums.size() - 1)
		{
			cost--;
			pos++;
			cost = max(cost, nums[pos]);
			cout << cost << " " << pos << endl;
		}
		if (pos == nums.size() - 1)
			return true;
		return false;
	}
};

int main()
{
	Solution s;
	cout << s.canJump({ 3, 2, 1, 0, 4 });
}