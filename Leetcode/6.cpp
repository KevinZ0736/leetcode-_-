#include <iostream>
#include<vector>
#include <string>
using namespace std;


// 直接二位矩阵模拟 

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		int gap = numRows * 2 - 1;

		vector<string> temp(numRows);
		if ((s.size() - 1) % (gap - 1) != 0) { int rez = ((s.size() - 1) / (gap - 1) + 1) * (gap - 1) + 1; s.resize(rez, '0'); }
		int end = gap; int head = 0;
		while (end <= s.size())
		{
			string strp(s.begin() + head, s.begin() + end);
			process(temp, strp, numRows);
			if (end != s.size())
			{
				temp[0].pop_back();
			}
			head = head + gap - 1;
			end = end + gap - 1;
		}
		string ans;
		for (auto m : temp)
		{
			ans = ans + m;
		}
		return ans;

	}

	void process(vector<string>& temp, string& str, int numRows)
	{
		for (int head = 0, end = numRows * 2 - 2, i = 0; head <= end, i < numRows; head++, end--, i++)
		{
			if (str[head] == '0')
			{
				continue;
			}
			if (str[head] != '0' && str[end] != '0' && head == end)
			{
				temp[i].push_back(str[head]);
				continue;
			}
			if (str[head] != '0')
				temp[i].push_back(str[head]);
			if (str[end] != '0')
				temp[i].push_back(str[end]);
		}
	}
};

//class Solution {
//public:
//	string convert(string s, int numRows) {
//		int n = s.length(), r = numRows;
//		if (r == 1 || r >= n) {
//			return s;
//		}
//		int t = r * 2 - 2;
//		int c = (n + t - 1) / t * (r - 1);
//		vector<string> mat(r, string(c, 0));
//		for (int i = 0, x = 0, y = 0; i < n; ++i) {
//			mat[x][y] = s[i];
//			if (i % t < r - 1) {
//				++x; // 向下移动
//			}
//			else {
//				--x;
//				++y; // 向右上移动
//			}
//		}
//		string ans;
//		for (auto& row : mat) {
//			for (char ch : row) {
//				if (ch) {
//					ans += ch;
//				}
//			}
//		}
//		return ans;
//	}
//};



int main()
{
	Solution s;
	cout << s.convert("A", 2);
}