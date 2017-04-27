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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode  *p1=new ListNode(0),*p2;
        p1->next=head;
        p2=p1;
        if(p1->next==NULL||p1->next->next==NULL)return p1->next;
        while(p1->next&&p1->next->next)
            if(p1->next->val!=p1->next->next->val)
                p1=p1->next;
            else
                p1->next=deleteVal(p1->next,p1->next->val);
        return p2->next;
    }
    ListNode* deleteVal(ListNode *head,int val){
        while(head!=NULL&&head->val==val)
            if(head->next!=NULL)
                *head=*(head->next);
            else
                return NULL;
        return head;
    }
};
