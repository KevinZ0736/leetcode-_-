#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        int top = 0;
        for (char ch : S) {
            if (top == 0 || S[top - 1] != ch) {
                S[top++] = ch;
            }
            else {
                top--;
            }
        }
        S.resize(top);
        return S;
    }
};

int main()
{
    Solution s;
    cout << s.removeDuplicates("aaaaaaaa");
}

