#include <iostream>
#include <algoritm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>&& people) {
		if (people.size() == 1)
			return people;
		vector<int> temp(2, 0);
		sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
			return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
			});
		for (int i = 1; i < people.size(); i++)
		{
			temp = people[i];
			for (int j = 0; j <= i; j++)
			{
				if (people[i][1] > 0)
				{
					if (people[i][0] <= people[j][0])
					{
						people[i][1]--;
					}
				}
				else if (people[i][1] == 0)
				{
					if (people[i][0] <= people[j][0] || j == i)
					{
						people.insert(people.begin() + j, temp);
						break;
					}
				}
				else {}
			}
			people.erase(people.begin() + i + 1);
		}

		return people;
	}
};


int main()
{
	Solution s;
	vector<vector<int>> result;
	result = s.reconstructQueue(vector<vector<int>>{{1, 0}, { 2, 0 }});
}