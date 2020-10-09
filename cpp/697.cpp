class Solution {
  // Runtime: 28 ms, faster than 98.39% of C++ online submissions for Degree of
  // an Array. Memory Usage: 12.4 MB, less than 92.00% of C++ online submissions
  // for Degree of an Array.
public:
  int findShortestSubArray(vector<int> &nums) {
    unordered_map<int, tuple<int, int, int>> hashmap;
    for (int i = 0; i < nums.size(); ++i) {
      if (auto it = hashmap.find(nums[i]); it != end(hashmap)) {
        auto &[first, last, count] = it->second;
        last = i;
        ++count;
      } else {
        hashmap.insert({nums[i], {i, i, 1}});
      }
    }
    auto ret = max_element(begin(hashmap), end(hashmap),
                           [](const auto &a, const auto &b) {
                             if (get<2>(a.second) == get<2>(b.second))
                               return get<1>(a.second) - get<0>(a.second) >
                                      get<1>(b.second) - get<0>(b.second);
                             return get<2>(a.second) < get<2>(b.second);
                           });
    return ret == end(hashmap) ? 0
                               : get<1>(ret->second) - get<0>(ret->second) + 1;
  }
};