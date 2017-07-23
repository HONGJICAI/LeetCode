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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        vector<int>nums;
        helper(res,root,nums,0);
        for(int i=0;i<res.size();++i)
            res[i]/=nums[i];
        return res;
    }
    void helper(vector<double>&res,TreeNode* root,vector<int>&nums,int i){
        if(root==NULL)
            return;
        if(nums.size()==i){
            nums.emplace_back(1);
            res.emplace_back(root->val);
        }
        else{
            ++nums[i];
            res[i]+=root->val;
        }
        helper(res,root->left,nums,i+1);
        helper(res,root->right,nums,i+1);
    }
};
