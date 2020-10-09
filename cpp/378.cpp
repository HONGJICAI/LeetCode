// priority_queue.cpp
class Solution {
  struct Node {
    int x, y;
    int val;
  };
  struct compare {
    bool operator()(Node &a, Node &b) { return a.val > b.val; }
  };

public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<int>> visited(row, vector<int>(col, 0));
    priority_queue<Node, vector<Node>, compare> qe;
    qe.push(Node{0, 0, matrix[0][0]});
    visited[0][0] = 1;
    while (--k) {
      Node cur = qe.top();
      if (cur.x + 1 < row && visited[cur.x + 1][cur.y] == 0) {
        qe.push(Node{cur.x + 1, cur.y, matrix[cur.x + 1][cur.y]});
        visited[cur.x + 1][cur.y] = 1;
      }
      if (cur.y + 1 < col && visited[cur.x][cur.y + 1] == 0) {
        qe.push(Node{cur.x, cur.y + 1, matrix[cur.x][cur.y + 1]});
        visited[cur.x][cur.y + 1] = 1;
      }
      qe.pop();
    }
    return qe.top().val;
  }
};
// sort.cpp
class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    multiset<int> res;
    for (auto &arr : matrix)
      res.insert(arr.begin(), arr.end());
    auto it = res.begin();
    for (int i = 1; i < k; ++i)
      ++it;
    return *it;
  }
};
class Solution2 {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    vector<int> res;
    for (auto &arr : matrix)
      res.insert(res.end(), arr.begin(), arr.end());
    sort(res.begin(), res.end());
    return res[k - 1];
  }
};
