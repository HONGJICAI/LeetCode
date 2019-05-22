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
        auto h=ListNode(0);
        h.next=head;
        auto p1=&h,p2=&h;
        for(int i=0;i<=n;++i)
            p1=p1->next;
        while(p1){
            p2=p2->next;
            p1=p1->next;
        }
        p2->next=p2->next->next;
        return h.next;
    }
};