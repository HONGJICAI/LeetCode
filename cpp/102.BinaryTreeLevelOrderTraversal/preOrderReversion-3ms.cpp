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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        preOrder(0,root,result);
        return result;
    }
    void preOrder(int i,TreeNode* root,vector<vector<int>>&nums){
        if(root==NULL)return;
        if(nums.size()==i)
            nums.push_back(vector<int>());
        nums[i].push_back(root->val);
        preOrder(i+1,root->left,nums);
        preOrder(i+1,root->right,nums);
    }
};
