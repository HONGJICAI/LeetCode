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
    ListNode* middleNode(ListNode* head) {
        auto pFront = head, pBack = head;
        while(pBack){
            pBack=pBack->next;
            if(!pBack)
                break;
            pFront=pFront->next;
            pBack=pBack->next;
        }
        return pFront;
    }
};
