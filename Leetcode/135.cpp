#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>&& ratings) {
		if (ratings.size() == 1)
			return 1;
		int sum = 0;
		vector<int> can(ratings.size(), 1);

		for (int i = 1; i < ratings.size(); i++)
		{
			if (ratings[i - 1] < ratings[i])
			{
				can[i] = can[i - 1] + 1;
			}
		}
		for (int i = ratings.size() - 1; i > 0; i--)
		{
			if (ratings[i - 1] > ratings[i])
			{
				can[i - 1] = max(can[i] + 1, can[i - 1]);
			}
		}
		for (auto x : can)
		{
			sum = sum + x;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.candy({ 1,3,4,5,2 });
}