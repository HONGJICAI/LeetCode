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
        int high=0,current;
        ListNode *head=NULL,*tail=NULL;
        while(l1!=NULL&l2!=NULL){
            current=l1->val+l2->val+high;
            if(current>=10){
                current-=10;
                high=1;
            }
            else{
                high=0;
            }
            ListNode *currentNode=new ListNode(current);
            if(head==NULL){
                head=currentNode;
                tail=currentNode;
            }
            else{
                tail->next=currentNode;
                tail=currentNode;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            current=l1->val+high;
            if(current>=10){
                current-=10;
                high=1;
            }
            else{
                high=0;
            }
            ListNode *currentNode=new ListNode(current);
            tail->next=currentNode;
            tail=currentNode;
            l1=l1->next;
        }
        while(l2!=NULL){
            current=l2->val+high;
            if(current>=10){
                current-=10;
                high=1;
            }
            else{
                high=0;
            }
            ListNode *currentNode=new ListNode(current);
            tail->next=currentNode;
            tail=currentNode;
            l2=l2->next;
        }
        if(high!=0){
            ListNode *currentNode=new ListNode(high);
            tail->next=currentNode;
            tail=currentNode;
        }
        return head;
    }
};
