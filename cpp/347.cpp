// hashmap+bucketsort+29ms.cpp
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> hashmap;
    for (auto num : nums)
      hashmap[num]++;
    int i, j, n = nums.size();
    vector<vector<int>> res(n);
    for (auto pairs : hashmap)
      res[pairs.second - 1].emplace_back(pairs.first);
    vector<int> r(k);
    for (i = 0, j = n - 1; i < k;)
      if (res[j].size() > 0) {
        r[i++] = res[j].back();
        res[j].pop_back();
      } else
        --j;
    return r;
  }
};
// hashmap+heap+19ms.cpp
class Solution2 {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> hashmap;
    for (auto num : nums)
      hashmap[num]++;
    vector<pair<int, int>> res(hashmap.size());
    int i = 0;
    for (auto pairs : hashmap)
      res[i++] = pairs;
    vector<int> r(k);
    make_heap(res.begin(), res.end(), [](pair<int, int> &a, pair<int, int> &b) {
      return a.second < b.second;
    });
    for (i = 0; i < k;) {
      r[i++] = res.front().first;
      pop_heap(res.begin(), res.end(),
               [](pair<int, int> &a, pair<int, int> &b) {
                 return a.second < b.second;
               });
      res.pop_back();
    }
    return r;
  }
};
// hashmap+multimap+22ms.cpp
class Solution3 {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> hashmap;
    vector<int> res(k);
    multimap<int, int> treemap;
    for (auto num : nums)
      hashmap[num]++;
    for (auto pairs : hashmap)
      treemap.insert(make_pair(pairs.second, pairs.first));
    int i = 0;
    for (auto it = treemap.rbegin(); i < k; ++it)
      res[i++] = it->second;
    return res;
  }
};
