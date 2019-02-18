/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    pair<ListNode*,ListNode*> helper(ListNode *head){
        if(!head)
            return {nullptr,nullptr};
        ListNode lh(0),rh(0);
        ListNode *l=&lh,*r=&rh,*h=head;
        for(auto p=head->next;p;p=p->next)
            if(h->val<p->val)
                r=r->next=p;
            else
                l=l->next=p;
        r->next=l->next=nullptr;
        auto lpart=helper(lh.next),rpart=helper(rh.next);
        if(lh.next)
            lpart.second->next=h;
        h->next=rpart.first;
        return {lh.next?lpart.first:h,rh.next?rpart.second:h};
    }
public:
    ListNode* sortList(ListNode* head) {
        return helper(head).first;
    }
};
