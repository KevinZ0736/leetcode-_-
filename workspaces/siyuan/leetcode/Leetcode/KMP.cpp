#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNext(const string& str)
{
	vector<int> next; 
	next.resize(str.length(),0);//初值全为0，也可以达到效果，start退到底都不匹配，那就默认第一个，赋值为0
	int start=0; int end;
	for (end = 1; end < str.size(); end++)
	{
		while (start > 0 && str[start] != str[end])
		{
			start = next[start-1];
		}

		if (str[end] == str[start])
		{
			start++;
			
		}
		next[end] = start;
	}
	return next;
}

int KMP(const string& str,const string& tar)
{
	if (tar.length() > str.length()) { return -1; }

	vector<int>&& next = getNext(tar);
	int s = 0; int t = 0;
	
	while (s < str.length() && t < tar.length())
	{
		if (str[s] == tar[t])
		{
			s++;
			t++;
		}
		else
		{
			if (t != 0) { t = next[t - 1]; }
			else {  s++; }
		}
	}
	if (t >= tar.length())
	{
		return s - tar.length();
	}
	else { return -1; }
	
}

int main()
{
	string s = "sdjhjjhhsadasd";
	string t = "djhjj";
	cout << KMP(s,t)+1 << " ";
}