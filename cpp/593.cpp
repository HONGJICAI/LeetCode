class Solution {
  // Runtime: 4 ms, faster than 88.89% of C++ online submissions for Valid
  // Square. Memory Usage: 8.4 MB, less than 65.97% of C++ online submissions
  // for Valid Square.
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    auto d = [](vector<int> &p1, vector<int> &p2) {
      return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
             (p1[1] - p2[1]) * (p1[1] - p2[1]);
    };
    unordered_set<int> s(
        {d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4)});
    return !s.count(0) && s.size() == 2;
  }
};