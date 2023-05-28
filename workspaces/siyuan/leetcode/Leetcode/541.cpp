#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

    string reverseStr(string s, int k) {
            int n = s.length();
            for (int i = 0; i < n; i += 2 * k) 
            {
                reverse(s, i, min(i + k-1, n));
            }
            return s;
        }

    void reverse(string &s,int start,int  end)
    {
        char tmp;
        while (start < end)
        {
            tmp = s[start];
            s[start++] = s[end];
            s[end--] = tmp; 
        }
    }
};