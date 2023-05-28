#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string n : tokens)
        {
            if ((n[0] == '+' || n[0] == '-' || n[0] == '*' || n[0] == '/'))
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                if (n[0] == '+') { nums.push(num1 + num2); }
                else if (n[0] == '-') { nums.push(num1 - num2); }
                else if (n[0] == '*') { nums.push(num1 * num2); }
                else if (n[0] == '/') { nums.push(num1 / num2); }
                

            }
            else {
              nums.push(atoi(n.c_str()));
            }
            
        }
        int& re = nums.top();
        return re;
    }
};

int main()
{
    Solution s;
    vector<string> tokens({ "10","6","9","3","+","-11","*","/","*","17","+","5","+"});
    cout<<s.evalRPN(tokens);
}