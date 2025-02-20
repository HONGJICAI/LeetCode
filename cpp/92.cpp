class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n)
            return head;
        ListNode newhead(0, head);
        auto left = &newhead;
        n -= m - 1;
        while (--m)
            left = left->next;
        auto right = left->next;
        ListNode *pre = nullptr, *now = right;
        while (n--) {
            ListNode* next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        left->next = pre;
        right->next = now;
        return newhead.next;
    }
};
