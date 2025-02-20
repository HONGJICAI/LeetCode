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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        for (auto p = head; p->next != nullptr;) {
            if (p->next->val == p->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
    }
};
