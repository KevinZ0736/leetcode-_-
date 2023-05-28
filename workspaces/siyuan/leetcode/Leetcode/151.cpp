#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int start, end; int len = s.size() - 1;
        if (s.size() == 0) { return s; }
        for (int i = len; i >= 0; i--)
        {
            if (s[i] > ' ')
            {
                if (i == len || s[i + 1] == ' ') { end = i; }
                if (i == 0 || s[i - 1] == ' ')
                {
                    start = i;
                    s.append(s, start, end - start + 1);
                    s = s + ' ';
                }
            }

        }
        s.erase(0, len + 1);
        return s;
    }
};