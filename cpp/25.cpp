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
// recursion.cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1)
            return head;
        auto cur = head;
        int count = 0;
        for (; count < k && cur != nullptr; ++count)
            cur = cur->next;
        if (count == k) {
            auto tail = reverseKGroup(cur, k);
            auto pre = tail, now = head;
            while (now != cur) {
                auto next = now->next;
                now->next = pre;
                pre = now;
                now = next;
            }
            return pre;
        }
        return head;
    }
};
