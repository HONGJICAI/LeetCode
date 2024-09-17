// iteration.cpp
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
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode *pre = nullptr, *now = head;
    while (now) {
      ListNode *next = now->next;
      now->next = pre;
      pre = now;
      now = next;
    }
    return pre;
  }
};
// recursion.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  ListNode *impl(ListNode *pre, ListNode *now) {
    ListNode *next = now->next;
    now->next = pre;
    if (!next)
      return now;
    return impl(now, next);
  }
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next)
      return head;
    return impl(nullptr, head);
  }
};
