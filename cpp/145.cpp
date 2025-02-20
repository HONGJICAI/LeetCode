/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        stack<pair<TreeNode*,int>> st({{root, 0}});
        vector<int> result;
        while (!st.empty()) {
            auto &[node, state] = st.top();
            if (state == 0){
                if (node->left)
                    st.push({node->left, 0});
            } else if (state == 1) {
                if(node->right)
                    st.push({node->right, 0});
            } else {
                result.push_back(node->val);
                st.pop();
            }
            state++;
        }
        return result;
    }
};