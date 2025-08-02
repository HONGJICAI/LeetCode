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
class Solution { // iteration 8ms
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto h = ListNode(0);
        auto p = &h;
        while (l1 && l2) {
            auto& smallP = l1->val < l2->val ? l1 : l2;
            p = p->next = smallP;
            smallP = smallP->next;
        }
        p->next = l1 ? l1 : l2;
        return h.next;
    }
};
class Solution2 { // recursion
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        auto &smaller = l1->val < l2->val ? l1 : l2,
             larger = l1->val < l2->val ? l2 : l1;
        smaller->next = mergeTwoLists(smaller->next, larger);
        return smaller;
    }
};
