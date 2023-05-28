#include<iostream>
#include<vector>
using namespace std;
//Ö±½ÓË«Ö¸Õë
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* start = new ListNode(0,head);
        ListNode* end = head; int len = 0; int count;
        while (end->next != nullptr) { end = end->next; len++; }
        cout << end->val;
        end->next = head->next;
        if (len % 2 != 0) { count = len / 2; count++; }
        else { count = len / 2; }
        int i = 0;

        while(count--)
        {
            int temp;
            ListNode* p = getpointer(end, (len - i));
            ListNode* q = getpointer(head->next, i);
            temp = p->val;
            p->val = q->val;
            q->val = temp;
            i++;
        }
        end->next = nullptr;
        return head;
    }

    ListNode* getpointer(ListNode *a,int gap)
    {
        ListNode* m = a;
        while (gap--)
        {
            m = m->next;
        }
        return m;
    }
};

int main()
{
    ListNode* l5 = new ListNode(5);
    ListNode* l4 = new ListNode(4, l5);
    ListNode *l3 = new ListNode(3,l4);
    ListNode *l2 = new ListNode(2,l3);
    ListNode* l1 = new ListNode(1, l2);
    ListNode* head = new ListNode(0,l1);
    Solution s;
    ListNode* h = s.reverseList(head);
    ListNode* p = head->next;
    while (p != nullptr) { cout << p->val << " "; p = p->next; }
}