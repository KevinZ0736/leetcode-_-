#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sum[26] = { 0 };
        for (auto i = s.begin(); i < s.end(); i++)
        {
            sum[*i - 'a']++;
        }
        for (auto i = t.begin(); i < t.end(); i++)
        {
            sum[*i - 'a']--;
        }
        for (int i = 0;i<26;i++)
        {
            if (sum[i] != 0) { return false; }
        }
        return true;
    }
};