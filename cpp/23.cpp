/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// make_heap.cpp
class Solution {
public:
    static bool heapComp(ListNode* a, ListNode* b) { return a->val > b->val; }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        auto curNode = &head;
        vector<ListNode*> v;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                v.push_back(lists[i]);
        }
        ranges::make_heap(v, heapComp); // vector -> heap data strcture

        while (v.size() > 0) {
            curNode = curNode->next = v.front();
            ranges::pop_heap(v, heapComp);
            v.pop_back();
            if (curNode->next) {
                v.push_back(curNode->next);
                ranges::push_heap(v, heapComp);
            }
        }
        return head.next;
    }
};
// priorityQueue.cpp
class Solution2 {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, deque<ListNode*>, compare> pq;
        ListNode p(0), *tail = &p;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                pq.push(lists[i]);
        while (!pq.empty()) {
            tail = tail->next = pq.top();
            pq.pop();
            if (tail->next)
                pq.push(tail->next);
        }
        return p.next;
    }
};
