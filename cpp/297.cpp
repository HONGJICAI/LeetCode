// preorder.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  TreeNode *de_preorder(vector<string> &arr, int &index) {
    if (arr[index] == "#")
      return nullptr;
    TreeNode *root = new TreeNode(stoi(arr[index]));
    root->left = de_preorder(arr, ++index);
    root->right = de_preorder(arr, ++index);
    return root;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (root == NULL)
      return "#\n";
    return to_string(root->val) + "\n" + serialize(root->left) +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    stringstream ss(data);
    vector<string> arr;
    string str;
    while (!ss.eof()) {
      ss >> str;
      arr.push_back(str);
    }
    int index = 0;
    return de_preorder(arr, index);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
