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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode *head,*tail;
        if(l1->val<l2->val){
            head=l1;
            l1=l1->next;
        }
        else{
            head=l2;
            l2=l2->next;
        }
        tail=head;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                tail->next=l1;
                tail=tail->next;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                tail=tail->next;
                l2=l2->next;
            }
        }
        if(l1==NULL)
        tail->next=l2;
        else
        tail->next=l1;
        return head;
    }
};
