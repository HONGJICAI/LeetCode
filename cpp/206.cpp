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
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *pre = NULL, *now = head;
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
public:
  ListNode *reverseList(ListNode *head) {
    if (head == NULL)
      return head;
    if (head->next == NULL)
      return head;
    return recursivelyReverse(NULL, head);
  }
  ListNode *recursivelyReverse(ListNode *pre, ListNode *now) {
    ListNode *next = now->next;
    now->next = pre;
    if (next == NULL)
      return now;
    return recursivelyReverse(now, next);
  }
};
