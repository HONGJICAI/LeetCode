// inorderTraversal.cpp
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
    long long int last = 0x8000000000000000;
    bool valid = 1;

public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return 1;
        isValidBST(root->left);
        valid = root->val > last ? valid : 0;
        last = root->val;
        isValidBST(root->right);
        return valid;
    }
};
