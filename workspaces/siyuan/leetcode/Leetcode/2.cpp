#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* H = new ListNode();
        ListNode* p = l1; ListNode* q = l2; int pg = 0;
        ListNode* h = H; int sum = 0;
        while (p != nullptr || q != nullptr)
        {
            if (q == nullptr)
            {
                h->next = p;
                if (p->val + pg > 9) { p->val = 0; pg = 1; }
                else { p->val = p->val + pg; pg = 0; }
                p = p->next;
                h = h->next;
            }
            else if (p == nullptr)
            {
                h->next = q;
                if (q->val + pg > 9) { q->val = 0; pg = 1; }
                else { q->val = q->val + pg; pg = 0; }
                q = q->next;
                h = h->next;
            }
            else
            {
                h->next = p;
                sum = p->val + pg + q->val;
                if (sum > 9) { p->val = sum%10; pg = 1; }
                else { p->val = sum; pg = 0; }
                p = p->next;
                h = h->next;

                ListNode* dq = q;
                q = q->next;
                delete dq;
                dq = nullptr;
            }
        }
        if(pg==1)
        {
            ListNode* tail = new ListNode(1);
            h->next = tail;
        }
        h = H->next;
        delete H; H = nullptr;
        return h;
    }
};