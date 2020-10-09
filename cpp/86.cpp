// 1.cpp
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
  ListNode *partition(ListNode *head, int x) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *small = new ListNode(0), *p1 = small;
    ListNode *big = new ListNode(0), *p2 = big;
    while (head) {
      if (head->val < x) {
        p1->next = head;
        p1 = p1->next;
      } else {
        p2->next = head;
        p2 = p2->next;
      }
      head = head->next;
    }
    p1->next = big->next;
    p2->next = NULL;
    return small->next;
    ;
  }
};