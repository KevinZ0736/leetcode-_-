#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		if (dividend == INT_MIN && divisor == 1) return INT_MIN;
		int sum = 0;
		if (dividend < 0 && divisor < 0)
		{
			return dd(-dividend, -divisor);
		}
		else if (dividend > 0 && divisor > 0)
		{
			return dd(dividend, divisor);
		}
		else {
			if (dividend < 0)
				return -dd(-dividend, divisor);
			if (divisor < 0)
				return -dd(dividend, -divisor);
		}
		return 0;
	}
	int dd(int a, int b) {  // 似乎精髓和难点就在于下面这几句
		if (a < b) return 0;
		int count = 1;
		int tb = b; // 在后面的代码中不更新b
		while (tb <= (a - tb)) {
			count = count + count; // 最小解翻倍
			tb = tb + tb; // 当前测试的值也翻倍
		}
		return count + dd(a - tb, b);
	}
};