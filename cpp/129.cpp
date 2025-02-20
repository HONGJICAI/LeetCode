// recursion-3ms.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
    void calc(TreeNode* root, int value, int& sum) {
        if (root == nullptr)
            return;
        value = value * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += value;
            return;
        }
        calc(root->left, value, sum);
        calc(root->right, value, sum);
    }

  public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        calc(root, 0, sum);
        return sum;
    }
};