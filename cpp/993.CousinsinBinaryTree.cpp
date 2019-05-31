/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // Runtime: 0 ms
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int found = 0;
        int p[2]={-2,-2};
        while (q.size()) {
            auto size = q.size();
            while (size--) {
                auto n = q.front();
                q.pop();
                if (n) {
                    if (n->val == x || n->val == y)
                        p[found++]=size;
                    q.push(n->left), q.push(n->right);
                }
            }
            if(found)
                return found == 2&&p[0]/2!=p[1]/2;
        }
        return false;
    }
};