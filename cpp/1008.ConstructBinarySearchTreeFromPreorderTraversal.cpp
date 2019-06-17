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
//Runtime: 4 ms, faster than 96.40% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
//Memory Usage: 8.7 MB, less than 97.42% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(not preorder.size())
            return nullptr;
        auto r=new TreeNode(preorder[0]);
        auto now=r;
        vector<TreeNode*>st;
        for(int i=1;i<preorder.size();++i){
            auto t=preorder[i];
            if(t<now->val){
                st.push_back(now);
                now=now->left=new TreeNode(t);
            }
            else{
                while(st.size()&&t>st.back()->val){
                    now=st.back();
                    st.pop_back();
                }
                now=now->right=new TreeNode(t);
            } 
        }
        return r;
    }
};