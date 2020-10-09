// insertSort.cpp
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
  ListNode *insertionSortList(ListNode *head) {
    ListNode h(0);
    while (head) {
      ListNode *temp = &h;
      while (temp->next && temp->next->val < head->val)
        temp = temp->next;
      ListNode *cur = head;
      head = head->next;
      cur->next = temp->next;
      temp->next = cur;
    }
    return h.next;
  }
};
