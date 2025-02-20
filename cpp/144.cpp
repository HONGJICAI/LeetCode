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
class Solution2 {
  public:
    vector<int> preorderTraversal(TreeNode* root) {
        auto h = TreeNode(0, nullptr, root);
        stack<TreeNode*> st({&h});
        vector<int> result;
        while (!st.empty()) {
            root = st.top()->right;
            st.pop();
            while (root) {
                result.push_back(root->val);
                st.push(root);
                root = root->left;
            }
        }
        return result;
    }
};
