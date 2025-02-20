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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode h(0, head), *tail = &h;
        int len = 0;
        for (; tail->next; tail = tail->next) {
            len++;
        }
        k %= len;
        if (k == 0)
            return head;
        auto p = &h;
        for (int i = 0; i < len - k; i++)
            p = p->next;
        ListNode* newhead = p->next;
        tail->next = head;
        p->next = nullptr;
        return newhead;
    }
};
