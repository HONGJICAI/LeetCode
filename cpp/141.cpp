// iteration.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode* head) {
        ListNode *p1 = head, *p2 = head;
        while (p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2 != nullptr)
                p2 = p2->next;
            if (p1 == p2 && p1 != nullptr)
                return 1;
        }
        return 0;
    }
};
