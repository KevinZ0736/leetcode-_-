#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getNext(const string& str)
    {

        vector<int> next;
        next.resize(str.length(), 0);
        int start = 0; int end;
        for (end = 1; end < str.length(); end++)
        {
            while (start > 0 && str[start] != str[end])
            {
                start = next[start - 1];
            }
            if (str[start] == str[end])
            {
                start++;
                next[end] = start;
                
            }
        }
        return next;
    }
    
    int KMP(const string& str, const string& tar)
    {
        if (tar.length() > str.length()) { return -1; }
        vector<int>&& next = getNext(tar);
        for (int i : next) { cout << i; }
        cout << endl;
        int s = 0; int t = 0;
        while (s < str.length() && t<tar.length())
        {
            if (str[s] == tar[t])
            {
                s++;
                t++;
            }
            else {
                if (t == 0) { s++; }
                else {
                    t = next[t - 1];
                }
            }
        }
        if (t >= tar.length())
        {
            return s - tar.length();
        }
        else { return -1; }
    }

    bool repeatedSubstringPattern(string s) {
        string m = s + s;
        string&& max = m.substr(1, m.length() - 2);
        int result = KMP(max, s);
        
        if (result < 0) { return false; }
        else { return true; }
    }
};

int main()
{
    Solution s;
    cout<<s.repeatedSubstringPattern("abaababaab");
}