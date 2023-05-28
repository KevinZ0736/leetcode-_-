#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                S.push(s[i]);
                flag = 1;
            }
            else {
                if (!S.empty())
                {
                    if (s[i] == ')' && S.top() == '(')
                    {
                        S.pop();
                    }
                    else if (s[i] == ']' && S.top() == '[')
                    {
                        S.pop();
                    }
                    else if (s[i] == '}' && S.top() == '{')
                    {
                        S.pop();
                    }
                    else { return false; }
                }
                else
                {
                    return false;
                }
            }
        }
        return S.empty();
    }
};

int main()
{
    Solution s;
    cout<<s.isValid("]");
}