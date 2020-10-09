// priority_queue.cpp
class Solution {
  struct cmp {
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
  };

public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> hashmap;
    for (auto &str : words)
      ++hashmap[str];
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    auto it = hashmap.begin();
    for (int i = 0; i < k; ++i)
      pq.push(*it++);
    vector<string> res(k);
    cmp compare;
    for (; it != hashmap.end(); ++it)
      if (compare(*it, pq.top())) {
        pq.pop();
        pq.push(*it);
      }
    for (int i = k - 1; i >= 0; i--) {
      res[i] = pq.top().first;
      pq.pop();
    }
    return res;
  }
};
