// make_heap.cpp
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
  static bool heapComp(ListNode *a, ListNode *b) { return a->val > b->val; }
  ListNode *mergeKLists(vector<ListNode *> &lists) { // make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode *> v;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i])
        v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp); // vector -> heap data strcture

    while (v.size() > 0) {
      curNode->next = v.front();
      pop_heap(v.begin(), v.end(), heapComp);
      v.pop_back();
      curNode = curNode->next;
      if (curNode->next) {
        v.push_back(curNode->next);
        push_heap(v.begin(), v.end(), heapComp);
      }
    }
    return head.next;
  }
};
// priorityQueue.cpp
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
    bool operator()(const ListNode *l, const ListNode *r) {
      return l->val > r->val;
    }
  };
  priority_queue<ListNode *, deque<ListNode *>, compare> pq;
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode p(0), *tail = &p;
    for (int i = 0; i < lists.size(); ++i)
      if (lists[i] != nullptr)
        pq.push(lists[i]);
    while (!pq.empty()) {
      tail->next = pq.top();
      tail = tail->next;
      pq.pop();
      if (tail->next != nullptr)
        pq.push(tail->next);
    }
    return p.next;
  }
};
