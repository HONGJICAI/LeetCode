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
  // Runtime: 32 ms, faster than 80.35% of C++ online submissions for Serialize
  // and Deserialize BST. Memory Usage: 25.8 MB, less than 39.25% of C++ online
  // submissions for Serialize and Deserialize BST.
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (not root)
      return " #";
    return " " + to_string(root->val) + serialize(root->left) +
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    stringstream ss(data);
    string now;
    TreeNode fakeRoot(0);
    auto p = &fakeRoot;
    vector<pair<TreeNode *, bool>> st{{p, 0}};
    while (ss >> now) {
      auto &[p, status] = st.back();
      if (now == "#") {
        if (not status)
          status = true;
        else
          st.pop_back();
      } else {
        auto &node = status ? p->right : p->left;
        if (not status)
          status = true;
        else
          st.pop_back();
        node = new TreeNode(stoi(now));
        st.push_back({node, false});
      }
    }
    return fakeRoot.left;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));