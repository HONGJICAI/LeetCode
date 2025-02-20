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
class Solution { // recursion
public:
    ListNode* swapPairs(ListNode* head) {
        function<ListNode*(ListNode*, ListNode*, ListNode*)> swap =
            [&swap](ListNode* a, ListNode* b, ListNode* cur) {
                if (a && b) {
                    b->next = a;
                    a->next = cur;
                }
                if (cur && cur->next)
                    a->next = swap(cur, cur->next, cur->next->next);
                return b;
            };
        if (head && head->next)
            return swap(head, head->next, head->next->next);
        return head;
    }
};
class Solution2 { // iteration
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        auto h = ListNode(0, head);
        auto p = &h;
        while (p->next && p->next->next) {
            auto l = p->next, r = p->next->next;
            auto next = r->next;
            p->next = r;
            r->next = l;
            l->next = next;
            p = l;
        }
        return h.next;
    }
};