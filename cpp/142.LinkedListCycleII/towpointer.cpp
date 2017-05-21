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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1=hasCycle(head),*p2=head;
        if(p1==NULL)return NULL;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
    ListNode *hasCycle(ListNode *head){
        ListNode *fast=head,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)return fast;
        }
        return NULL;
    }
};
