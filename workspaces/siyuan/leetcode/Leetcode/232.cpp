#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
private:
	stack<int> s1;
	stack<int> s2;

	void inS1()//每次在第一个栈入栈前，将他的元素清空
	{
		while (s1.empty() != true)
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
public:
	void push(int x)
	{
		s1.push(x);
	}

	int pop() {
		if(s2.empty())
		{
			inS1();
		}
		int x = s2.top();
		s2.pop();
		return x;
	}
	
	int peek()
	{
		inS1();
		int x = s2.top();
		return x;

	}

	bool empty()
	{
		return s1.empty() && s2.empty();
	}
};