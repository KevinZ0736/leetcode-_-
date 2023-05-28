#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> str{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

	void getstring(vector<string>& result, string& tmp, string& digits, int level, int index)
	{
		if (tmp.size() == digits.size() && level == digits.size())
		{
			result.emplace_back(tmp);
		}
		else
		{
			for (int i = index; i < str[digits[level] - '0'].size(); i++)
			{
				tmp.push_back(str[digits[level] - '0'][i]);
				getstring(result, tmp, digits, level + 1, index);
				tmp.pop_back();
			}
		}
	}

	vector<string> letterCombinations(string digits) {
		int len = digits.size();
		string tmp;
		vector<string> result;
		if (digits.size() == 0) { return result; }
		getstring(result, tmp, digits, 0, 0);
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.letterCombinations("23").size();
}