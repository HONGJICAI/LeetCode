/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    priority_queue<ListNode*,deque<ListNode*>,compare>pq;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *p=new ListNode(0),*tail=p;
        for(int i=0;i<lists.size();++i)
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        while(!pq.empty()){
            tail->next=pq.top();
            tail=tail->next;
            pq.pop();
            if(tail->next!=NULL)
                pq.push(tail->next);
        }
        return p->next;
    }
};
