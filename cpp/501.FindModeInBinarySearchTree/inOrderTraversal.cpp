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
    vector<int>result;
    int curCount=0;
    int maxCount=0;
    int lastValue;
    bool firstTime=1;
public:
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return result;
    }
    void inOrder(TreeNode* root){
        if(root==NULL)
            return;
        inOrder(root->left);
        if(firstTime){
            lastValue=root->val;
            firstTime=0;
        }
        if(lastValue!=root->val){
            curCount=0;
            lastValue=root->val;
        }
        if(lastValue==root->val){
            ++curCount;
            if(curCount==maxCount){
                result.push_back(lastValue);
            }
            else if(curCount>maxCount){
                maxCount=curCount;
                result.clear();
                result.push_back(lastValue);
            }
        }
        inOrder(root->right);
    }
};
