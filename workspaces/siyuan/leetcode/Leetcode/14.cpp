#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        char c; int flag; string m="";
        for (int i = 0; i < strs[0].length(); i++)
        {
            c = strs[0][i];
            flag = 1;
            for (auto str : strs)
            {
                if (str[i] != c)
                {
                    flag = 0; break;
                }
            }
                if(flag)
                {
                    m=m+c;
                }
                else
                {
                    return m;
                }
            
        }

    }
};

int main()
{
    Solution s;
    string a =s.longestCommonPrefix({ "dog","racecar","car" });
    cout << a << endl;
}