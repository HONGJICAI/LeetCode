/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { // recursion 0ms
public:
    ListNode* swapPairs(ListNode* head) {
        function<ListNode*(ListNode*,ListNode*,ListNode*,ListNode*)> swap= [&swap](ListNode* pre,ListNode *a,ListNode* b,ListNode *cur){
            if(a&&b){
                b->next=a;
                a->next=cur;
                if(pre)
                    pre->next=b;
            }
            if(cur&&cur->next)
                swap(a,cur,cur->next,cur->next->next);
            return b;
        };
        if(head&&head->next)
            return swap(nullptr,head,head->next,head->next->next);
        return head;
    }
};
class Solution { // iteration 4ms
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        auto h=ListNode(0);
        h.next=head;
        auto p=&h;
        while(p->next&&p->next->next){
            auto l=p->next,r=p->next->next;
            auto next=r->next;
            p->next=r;
            r->next=l;
            l->next=next;
            p=l;
        }
        return h.next;
    }
};