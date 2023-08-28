#include< iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>&& nums) {
		int head = 0; int end = head; int sum = INT_MIN; int count = nums[head];
		while (end < nums.size())
		{
			while (count >= 0 && end < nums.size() - 1)
			{
				sum = max(sum, count);
				end++;
				count += nums[end];

			}
			if (end < nums.size() - 1)
			{
				sum = max(sum, count);
				head = end + 1;
				end++;
				count = nums[head];
			}
			else if (end == nums.size() - 1)
			{
				end++;
			}
			sum = max(sum, count);
		}
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.maxSubArray({ -1,-2 });
}