#include<iostream>
#include<string>
#include<vector>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* vhead = new ListNode(0, head);
        ListNode* p; ListNode* q;
        p = vhead;
        q = p->next;
        while (q != nullptr)
        {
            if (q->val == val)
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else {
                if (q != nullptr)
                    p = p->next;
                q = q->next;
            }
        }
        p = vhead->next;
        delete(vhead); vhead = nullptr;
        return p;
    }
};