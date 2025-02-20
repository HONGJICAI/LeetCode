// recursion.cpp
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
    TreeNode* recursion(int low, int high, vector<int>& nums) {
        if (low >= high)
            return nullptr;
        int mid = (low + high) / 2;
        TreeNode* p = new TreeNode(nums[mid]);
        p->left = recursion(low, mid, nums);
        p->right = recursion(mid + 1, high, nums);
        return p;
    }

  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(0, nums.size(), nums);
    }
};
