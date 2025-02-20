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
    vector<vector<int>> result;
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr)
            return;
        if (depth == result.size()) {
            result.push_back({});
        }
        result[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root, 0);
        return {result.rbegin(), result.rend()};
    }
};
