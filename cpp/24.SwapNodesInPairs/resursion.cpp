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
    ListNode* swapPairs(ListNode* head) {
        if(head&&head->next)
            return swap(NULL,head,head->next,head->next->next);
        return head;
    }
    ListNode* swap(ListNode* pre,ListNode *a,ListNode* b,ListNode *cur){
        if(a&&b){
            b->next=a;
            a->next=cur;
            if(pre)
                pre->next=b;
        }
        if(cur&&cur->next)
            swap(a,cur,cur->next,cur->next->next);
        return b;
    }
};
