// noExtraSpace-40ms.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  ListNode *getMedian(ListNode *head) {
    ListNode *p1 = head, *p2 = head, *p3 = nullptr;
    while (p2 && p2->next) {
      p2 = p2->next->next;
      p3 = p1;
      p1 = p1->next;
    }
    if (p3)
      p3->next = nullptr;
    return p1;
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    auto median = getMedian(head);
    if (!median)
      return nullptr;
    auto root = new TreeNode(median->val);
    if (head != median)
      root->left = sortedListToBST(head);
    if (median)
      root->right = sortedListToBST(median->next);
    return root;
  }
};
