#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minCost(string colors, vector<int>& neededTime) {
		if (colors.size() <= 1)
		{
			return 0;
		}
		int start = 0, end = 1, sum = 0;
		while (end < colors.size())
		{
			while (colors[start] == colors[end])
			{
				sum = sum + min(neededTime[start], neededTime[end]);
				start++;
				end++;
			}
			start++;
			end++;
		}
		return sum;
	}

};