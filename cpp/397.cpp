class Solution {
  // Memory Limit Exceeded
  // Last executed input 100000000
public:
  int integerReplacement(int n) {
    if (n == 1)
      return 0;
    deque<pair<int, int>> dq{{1, 0}};
    vector<int> visited(2 * n);
    visited[0] = visited[1] = 1;
    array<function<int(int)>, 3> ops = {
        [](int a) { return a * 2; },
        [](int a) { return a + 1; },
        [](int a) { return a - 1; },
    };
    while (dq.size()) {
      auto [k, count] = dq.front();
      for (auto &op : ops) {
        auto nextk = op(k);
        if (nextk > k and k > n)
          continue;
        if (nextk == n)
          return count + 1;
        if (not visited[nextk]) {
          visited[nextk] = 1;
          dq.push_back({nextk, count + 1});
        }
      }
      dq.pop_front();
    }
    return 0;
  }
};
class Solution {
  // Time Limit Exceeded
  // Last executed input 100000000
public:
  int integerReplacement(int n) {
    if (n == 1)
      return 0;
    deque<pair<int, int>> dq{{1, 0}};
    vector<int> visited(n + 1);
    unordered_set<int> visited2;
    visited[0] = visited[1] = 1;
    array<function<int(int)>, 3> ops = {
        [](int a) { return a * 2; },
        [](int a) { return a + 1; },
        [](int a) { return a - 1; },
    };
    while (dq.size()) {
      auto [k, count] = dq.front();
      for (auto &op : ops) {
        auto nextk = op(k);
        if (nextk > k and k > n)
          continue;
        if (nextk == n)
          return count + 1;
        if (nextk <= n and not visited[nextk]) {
          visited[nextk] = 1;
          dq.push_back({nextk, count + 1});
        }
        if (nextk > n and not visited2.count(nextk)) {
          visited2.insert(nextk);
          dq.push_back({nextk, count + 1});
        }
      }
      dq.pop_front();
    }
    return 0;
  }
};
class Solution {
  // Runtime: 4 ms, faster than 88.22% of C++ online submissions for Integer
  // Replacement. Memory Usage: 13 MB, less than 5.34% of C++ online submissions
  // for Integer Replacement.
  unordered_map<long long, int> visited;
  int compute(long long n) {
    if (n == 1)
      return 0;
    auto it = visited.find(n);
    if (it == end(visited))
      return (n & 1 == 1) ? visited[n] = 1 + min(compute(n + 1), compute(n - 1))
                          : visited[n] = 1 + compute(n / 2);
    return it->second;
  }

public:
  int integerReplacement(int n) { return compute(n); }
};