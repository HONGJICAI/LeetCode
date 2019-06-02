/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // Runtime: 36 ms, faster than 94.74% of C++ online submissions for Increasing Order Search Tree.
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = nullptr,*ret = nullptr;
        function<void(TreeNode*)> inorder = [&](auto node){
            if(not node)
                return;
            inorder(node->left);
            if(not head)
                ret = head = node;
            else
                head = head->right = node;
            head->left = nullptr;
            inorder(node->right);
        };
        inorder(root);
        return ret;
    }
};