#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>&& gas, vector<int>&& cost) {
		vector<int> remain(gas.size(), 0);

		for (int i = 0; i < cost.size(); i++)
		{
			remain[i] = gas[i] - cost[i];
		}

		int start = 0;
		int end = 1;
		int sum = remain[0];

		while (end != start && start < remain.size())
		{
			if (sum < 0)
			{
				if (start < end) { start = end - 1; }
				else { return -1; }
				while (++start < remain.size() && remain[start] < 0) {}
				if (start >= remain.size())
					return -1;
				end = (start + 1) % remain.size();
				sum = remain[start];
			}
			sum = sum + remain[end];
			end = (end + 1) % remain.size();
		}

		if (end == start && sum >= 0)
			return start;
		return -1;

	}
};

int main()
{
	Solution s;
	// cout << s.canCompleteCircuit({ 1,2,3,4,5 }, { 3,4,5,1,2 });
	cout << s.canCompleteCircuit({ 1,2,3,4,3,2,4,1,5,3,2,4 }, { 1,1,1,3,2,4,3,6,7,4,3,1 });

}