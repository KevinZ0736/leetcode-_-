#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int i = 0; int sum = 1; int len = n - 1; int x_start = 0; int y_start = 0;
        while (i < n / 2)
        {
            int x = x_start; int y = y_start;

            for (; x < x_start + len; x++)
            {
                result[y][x] = sum++;
            }

            for (; y < y_start + len; y++)
            {
                result[y][x] = sum++;
            }

            for (; x > x_start; x--)
            {
                result[y][x] = sum++;
            }

            for (; y > y_start; y--)
            {
                result[y][x] = sum++;
            }
            len = len - 2;
            x_start++;
            y_start++;
            i++;
        }
        if (n % 2 != 0) {
            int m = n / 2;
            result[m][m] = n * n;
        }
        return result;

    }
};

int main()
{
    Solution s;
    auto a = s.generateMatrix(3);
}