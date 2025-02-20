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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> qe({root});
        vector<vector<int>> result;
        int level = 0, size;
        while (!qe.empty()) {
            result.push_back(vector<int>(qe.size()));
            size = qe.size();
            for (int i = 0; i < size; ++i) {
                auto p = qe.front();
                qe.pop();
                result[level][i] = p->val;
                if (p->left != nullptr)
                    qe.push(p->left);
                if (p->right != nullptr)
                    qe.push(p->right);
            }
            if (qe.empty())
                break;
            ++level;
            result.push_back(vector<int>(qe.size()));
            for (int i = qe.size() - 1; i >= 0; --i) {
                auto p = qe.front();
                qe.pop();
                result[level][i] = p->val;
                if (p->left != nullptr)
                    qe.push(p->left);
                if (p->right != nullptr)
                    qe.push(p->right);
            }
            ++level;
        }
        return result;
    }
};