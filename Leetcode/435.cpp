#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>&& intervals) {
		if (intervals.size() == 1)
			return 0;

		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] < b[0]; });
		int sum = 0;

		function<int(int, int)> cmp = [&, intervals](int head, int end) ->int {
			if (intervals[head][1] >= intervals[end][1])
				return end;
			else if (intervals[head][1] < intervals[end][1])
				return head;
		};

		for (int head = 0, end = 1; end < intervals.size(); end++)
		{
			if (intervals[head][1] > intervals[end][0])
			{
				sum++;
				head = cmp(head, end);
			}
			else
			{
				head = end;
			}
		}

		return sum;

	}
};

int main()
{
	Solution s;
	s.eraseOverlapIntervals({ {0,2} ,{1,3},{2,4},{3,5},{4,6} });
}