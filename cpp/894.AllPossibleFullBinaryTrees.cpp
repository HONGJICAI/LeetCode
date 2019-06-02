/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //Runtime: 96 ms, faster than 95.53% of C++ online submissions for All Possible Full Binary Trees.
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<vector<TreeNode*>>memory={{},{new TreeNode(0)},{}};
        for(int i=3;i<=N;++i){
            vector<TreeNode*>cur;
            for(int l=1,r=i-2;l<i-1;++l,--r){
                if(memory[l].size()&&memory[r].size()){
                    for(auto left:memory[l]){
                        for(auto right:memory[r]){
                            auto root=new TreeNode(0);
                            root->left=left;
                            root->right=right;
                            cur.push_back(root);
                        }
                    }
                }
            }
            memory.push_back(move(cur));
        }
        return memory[N];
    }
};