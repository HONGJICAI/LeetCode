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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return 1;
        queue<TreeNode*>qe1,qe2;
        qe1.push(root->left);
        qe2.push(root->right);
        while(!qe1.empty()&&!qe2.empty()){
            TreeNode *r1=qe1.front();
            TreeNode *r2=qe2.front();
            qe1.pop();
            qe2.pop();
            if(r1&&r2){
                if(r1->val!=r2->val)
                    return 0;
                qe1.push(r1->left);
                qe1.push(r1->right);
                qe2.push(r2->right);
                qe2.push(r2->left);
            }
            else if(r1!=r2)
                return 0;
        }
        return 1;
    }
};
