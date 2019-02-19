/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* separate(ListNode *h){
        auto l=h,r=h;
        ListNode* pre=nullptr;
        while(r&&r->next){
            r=r->next->next;
            pre=l;
            l=l->next;
        }
        if(pre)
            pre->next=nullptr;
        return l;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        auto rp=separate(head);
        rp=sortList(rp);
        auto lp=sortList(head);
        auto h=ListNode(0);
        auto p=&h;
        while(lp&&rp){
            auto &smallP=(lp->val<rp->val)?lp:rp;
            p=p->next=smallP;
            smallP=smallP->next;
        }
        for(auto cur=lp?lp:rp;cur;cur=cur->next)
            p=p->next=cur;
        return h.next;
    }
};
