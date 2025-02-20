// 1.cpp
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto small = ListNode(0), big = ListNode(0);
        auto p1 = &small, p2 = &big;
        while (head) {
            if (head->val < x) {
                p1 = p1->next = head;
            } else {
                p2 = p2->next = head;
            }
            head = head->next;
        }
        p1->next = big.next;
        p2->next = nullptr;
        return small.next;
    }
};