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
    int countNodes(TreeNode* root) {
        int Deep = 0, result = 0;
        if (!root) return 0;
        TreeNode* temp = root, *cur = root;
        while(temp) {
            Deep++;
            temp=temp->left;
        }
        int parentHigh = Deep;//父节点的高度，也就是当前节点的高度
        
        while (parentHigh>1) {//parentHigh表示当前节点，因为要计算子节点即curHigh，所以不能等于0
            cur = root->left;
            int curHigh = parentHigh-1;//当前节点的子节点高度
            for (int i = curHigh; i > 1; i--) cur = cur->right;
            if (cur) {
                root = root->right;
                result += 1<<(curHigh-1);
            }else{
                root=root->left;
            }
            parentHigh--;        
        }
        if (root) result++;
        return result + (1<<(Deep-1))-1;
    }
    
    
};
