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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        auto cur = &head;
        int remain = 0;
        while (l1 || l2) {
            auto val = remain + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            cur = cur->next = new ListNode(val % 10);
            remain = val / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (remain)
            cur->next = new ListNode(remain);
        return head.next;
    }
};