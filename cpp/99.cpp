/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode *m1 = nullptr, *m2 = nullptr, *pre = nullptr;
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        if (pre) {
            if (!m1 && root->val < pre->val) {
                m1 = pre;
            }
            if (m1 && root->val < pre->val) {
                m2 = root;
            }
        }
        pre = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(m1->val, m2->val);
    }
};
