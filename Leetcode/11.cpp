#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>&& height) {
		int head = 0;
		int end = height.size() - 1;
		int sum = 0;
		while (head < end)
		{
			if (height[head] <= height[end])
			{
				sum = max((end - head) * height[head], sum);
				head++;
			}
			else {
				sum = max((end - head) * height[end], sum);
				end--;
			}
		}
		return sum;
	}
};

int main()
{
	Solution s;
	s.maxArea({ 1,8,6,2,5,4,8,3,7 });
}