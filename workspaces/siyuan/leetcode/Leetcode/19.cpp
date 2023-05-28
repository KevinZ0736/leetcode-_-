/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* H = new ListNode(0, head);
        int gap = n + 1;
        ListNode* p = H; ListNode* q = H;
        while (gap--) {
            if (p == nullptr && gap > 0)
            {
                return nullptr;
            }
            else
            {
                p = p->next;
            }
        }

        while (p != nullptr) {
            p = p->next;
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        delete p;
        p = nullptr;
        return H->next;
    }
};