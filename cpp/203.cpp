// iteration.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode* p = head;
        while (p) {
            if (p->next)
                if (p->next->val == val) {
                    p->next = p->next->next;
                    continue;
                }
            p = p->next;
        }
        return head;
    }
};
