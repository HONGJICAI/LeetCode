// mergeSort-52ms.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  ListNode *separate(ListNode *h) {
    auto l = h, r = h;
    ListNode *pre = nullptr;
    while (r && r->next) {
      r = r->next->next;
      pre = l;
      l = l->next;
    }
    if (pre)
      pre->next = nullptr;
    return l;
  }

public:
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;
    auto rp = separate(head);
    rp = sortList(rp);
    auto lp = sortList(head);
    auto h = ListNode(0);
    auto p = &h;
    while (lp && rp) {
      auto &smallP = (lp->val < rp->val) ? lp : rp;
      p = p->next = smallP;
      smallP = smallP->next;
    }
    for (auto cur = lp ? lp : rp; cur; cur = cur->next)
      p = p->next = cur;
    return h.next;
  }
};
// quickSortO1Space-744ms.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  pair<ListNode *, ListNode *> helper(ListNode *head) {
    if (!head)
      return {nullptr, nullptr};
    ListNode lh(0), rh(0);
    ListNode *l = &lh, *r = &rh, *h = head;
    for (auto p = head->next; p; p = p->next)
      if (h->val < p->val)
        r = r->next = p;
      else
        l = l->next = p;
    r->next = l->next = nullptr;
    auto lpart = helper(lh.next), rpart = helper(rh.next);
    if (lh.next)
      lpart.second->next = h;
    h->next = rpart.first;
    return {lh.next ? lpart.first : h, rh.next ? rpart.second : h};
  }

public:
  ListNode *sortList(ListNode *head) { return helper(head).first; }
};
