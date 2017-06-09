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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>arr1,arr2;
        while(l1){
            arr1.emplace_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            arr2.emplace_back(l2->val);
            l2=l2->next;
        }
        ListNode* p=new ListNode(0);
        int i,j,c=0,val;
        for(i=arr1.size()-1,j=arr2.size()-1;i>=0||j>=0||c>0;c=val/10){
            val=(i>=0?arr1[i--]:0) + (j>=0?arr2[j--]:0)+c;
            ListNode*node=new ListNode( val%10 );
            node->next=p->next;
            p->next=node;
        }
        return p->next;
    }
};
