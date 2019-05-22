/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { // iteration 8ms
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto h=ListNode(0);
        auto p=&h;
        while(l1&&l2){
            auto &smallP = l1->val<l2->val?l1:l2;
            p=p->next=smallP;
            smallP=smallP->next;
        }
        p->next=l1?l1:l2;
        return h.next;
    }
};
class Solution { // recursion
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
			return l2;
        if(l2==nullptr)
			return l1;
        if(l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
