class Solution {
  // Runtime: 4 ms, faster than 97.92% of C++ online submissions for Partition
  // Labels. Memory Usage: 8.7 MB, less than 73.77% of C++ online submissions
  // for Partition Labels.
public:
  vector<int> partitionLabels(string S) {
    vector<int> res, pos(26, 0);
    for (auto i = 0; i < S.size(); ++i)
      pos[S[i] - 'a'] = i;
    for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
      idx = max(idx, pos[S[i] - 'a']);
      if (idx == i)
        res.push_back(i - exchange(last_i, i + 1) + 1);
    }
    return res;
  }
};