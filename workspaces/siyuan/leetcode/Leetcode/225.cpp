#include<iostream>
#include<queue>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

    int move(queue<int>& Q1, queue<int>& Q2)
    {
        if(Q1.size()==1 && Q2.size()==0){ return Q1.front(); }
        while (Q1.size() > 1)
        {
             Q2.push(Q1.front());
             Q1.pop();
        }
        return Q1.front();
    }

public:
    MyStack() {
        
    }

    void push(int x) {
        if (q1.size() > 0)
        {
            q1.push(x);
        }
        else if (q2.size() > 0)
        {
            q2.push(x);
        }
        else
        {
            q1.push(x);
        }
    }

    int pop() {
        int x=0;
        if (this->empty()) { return false; }
        if (q1.size() == 0)
        {
            x = move(q2, q1);
            q2.pop();
        }
        else if (q2.size() == 0)
        {
            x = move(q1, q2);
            q1.pop();
        }
        return x;
    }

    int top() {
        int x=0;
        if (this->empty()) { return false; }
        if (q1.size() > 0)
        {
            x = q1.back();
       
        }
        else if (q2.size() > 0)
        {
             x = q2.back();
        }
        return x;
    }

    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
}