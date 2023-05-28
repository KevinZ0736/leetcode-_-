#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> target;
        
        for (int n1 : nums1)
        {
            for (int n2 : nums2)
            {
                target[n1 + n2]++;
            }
        }
        int tar; int sum = 0;
        for (int n3 : nums3)
        {
            for (int n4 : nums4)
            {
                tar = n3 + n4;
                if (target.find(-tar) != target.end())
                {
                    sum = sum + (*target.find(-tar)).second;
                }
            }
        }
        return sum;
    }
};