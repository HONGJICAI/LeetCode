// recursion-13ms.cpp
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
    vector<vector<int>> result;
    void hasSum(TreeNode* root, int sum, vector<int>& now) {
        if (root == nullptr)
            return;
        now.push_back(root->val);
        if (0 == sum - root->val && root->left == nullptr &&
            root->right == nullptr)
            result.push_back(now);
        hasSum(root->left, sum - root->val, now);
        hasSum(root->right, sum - root->val, now);
        now.pop_back();
    }

  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> now;
        hasSum(root, sum, now);
        return result;
    }
};