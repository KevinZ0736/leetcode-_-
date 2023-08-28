#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>&& matrix, int target) {
		int wid = matrix.size() - 1;
		int len = matrix[0].size() - 1;
		int l = 0; int w = 0;
		if (target<matrix[0][0] || target>matrix[wid][len])
			return false;

		while (w < wid)
		{
			if (target >= matrix[w][0] && target < matrix[w + 1][0])
				break;
			w++;
		}
		while (l <= len)
		{
			if (target == matrix[w][l])
				return true;
			l++;
		}

		return false;
	}
};

int main()
{
	Solution s;
	cout << s.searchMatrix({ {1}, {3} }, 3);
}