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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recursion(nums.begin(),0,nums.size());
    }
    TreeNode* recursion(vector<int>::iterator it,int left,int right){
        if(left>=right)
            return nullptr;
        auto maxIt=max_element(it+left,it+right);
        TreeNode *root=new TreeNode(*maxIt);
        root->left=recursion(it,left,(int)(maxIt-it));
        root->right=recursion(it,(int)(maxIt-it)+1,right);
        return root;
    }
};
