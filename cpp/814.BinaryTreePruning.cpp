/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //Runtime: 4 ms, faster than 91.95% of C++ online submissions for Binary Tree Pruning.
public:
    TreeNode* pruneTree(TreeNode* root) {
        function<bool(TreeNode*)> postorder=[&postorder](TreeNode* node){
            if(!node)
                return true;
            auto removeThis=node->val==0;
            auto removeL=postorder(node->left);
            if(removeL)
                node->left=nullptr;
            auto removeR=postorder(node->right);
            if(removeR)
                node->right=nullptr;
            removeThis=removeThis and removeL and removeR;
            return removeThis;
        };
        return postorder(root)?nullptr:root;
    }
};