// simple.cpp
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
  ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next)
      return head;
    ListNode odd(0), even(0);
    odd.next = head;
    even.next = head->next;
    ListNode *odd_tail = odd.next;
    ListNode *even_tail = even.next;
    head = head->next->next;
    while (head) {
      odd_tail = odd_tail->next = head;
      head = head->next;
      if (!head)
        break;
      even_tail = even_tail->next = head;
      head = head->next;
    }
    odd_tail->next = even.next;
    even_tail->next = nullptr;
    return odd.next;
  }
};
