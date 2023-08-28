#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>&& points) {
		if (points.size() == 1)
		{
			return 1;
		}

		sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] <= b[0]; });

		vector<int> temp(points[0]);
		int sum = 1;

		for (int i = 1; i < points.size(); i++)
		{
			if (temp[1] < points[i][0])
			{
				sum++;
				temp = points[i];
			}
			else
			{
				temp[0] = max(temp[0], points[i][0]);
				temp[1] = min(temp[1], points[i][1]);
			}
		}

		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.findMinArrowShots({ {10, 16},{2, 8},{1, 6},{7, 12} });
}