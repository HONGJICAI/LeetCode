// dp+inorder.cpp
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
    TreeNode* generate(TreeNode* root, int& val) {
        if (root == nullptr)
            return nullptr;
        TreeNode* l = generate(root->left, val);
        TreeNode* node = new TreeNode(val++);
        TreeNode* r = generate(root->right, val);
        node->left = l;
        node->right = r;
        return node;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {};
        vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
        dp[0].push_back(nullptr);
        for (int i = 1; i <= n; ++i) {
            int m = 0, n = i - 1;
            while (n >= 0) {
                for (auto lchild : dp[m]) {
                    for (auto rchild : dp[n]) {
                        TreeNode* node = new TreeNode(0);
                        node->left = lchild;
                        node->right = rchild;
                        dp[i].push_back(node);
                    }
                }
                ++m, --n;
            }
        }
        vector<TreeNode*> res;
        for (auto node : dp.back()) {
            int i = 1;
            res.push_back(generate(node, i));
        }
        return res;
    }
};
