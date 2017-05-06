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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1=new ListNode(0),*p2=new ListNode(0);
        p1->next=p2->next=head;
        for(int i=0;i<=n;++i)
            p1=p1->next;
        head=p2;
        while(p1!=NULL){
            head=head->next;
            p1=p1->next;
        }
        head->next=head->next->next;
        return p2->next;
    }
};
