#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>&& intervals) {
		if (intervals.size() == 1)
		{
			return intervals;
		}

		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
			{return a[0] < b[0];
			});

		vector<vector<int>> result;
		vector<int> temp = intervals[0];
		for (int head = 0, end = 1; end < intervals.size(); end++)
		{
			if (temp[1] >= intervals[end][0])
			{
				temp[1] = max(intervals[end][1], intervals[head][1]);
			}
			else
			{
				result.push_back(temp);
				temp = intervals[end];
				head = end;
			}
			if (end == intervals.size() - 1)
			{
				result.push_back(temp);
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	s.merge({ {1,3} ,{2,6},{8,10},{15,18} });
}