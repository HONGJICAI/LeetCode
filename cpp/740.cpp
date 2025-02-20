class Solution {
  // dfs Time Limit Exceeded
  //[12,32,93,17,100,72,40,71,37,92,58,34,29,78,11,84,77,90,92,35,12,5,27,92,91,23,65,91,85,14,42,28,80,85,38,71,62,82,66,3,33,33,55,60,48,78,63,11,20,51,78,42,37,21,100,13,60,57,91,53,49,15,45,19,51,2,96,22,32,2,46,62,58,11,29,6,74,38,70,97,4,22,76,19,1,90,63,55,64,44,90,51,36,16,65,95,64,59,53,93]
public:
  int deleteAndEarn(vector<int> &nums) {
    unordered_map<int, int> counter;
    for (auto num : nums)
      counter[num]++;
    unordered_set<int> used;
    using itr = decltype(counter)::iterator;
    int ret = 0;
    function<void(itr, itr, int)> dfs = [&dfs, &used, &ret](itr first, itr last,
                                                            int sum) {
      if (first == last) {
        ret = max(ret, sum);
        return;
      }
      if (not used.count(first->first + 1) and
          not used.count(first->first - 1)) {
        auto it = used.insert(first->first);
        auto itr = first;
        dfs(++itr, last, first->first * first->second + sum);
        used.erase(it.first);
      }
      dfs(++first, last, sum);
    };
    dfs(begin(counter), end(counter), 0);
    return ret;
  }
};
class Solution2 {
  // Runtime: 8 ms, faster than 94.04% of C++ online submissions for Delete and
  // Earn. Memory Usage: 11.2 MB, less than 31.37% of C++ online submissions for
  // Delete and Earn.
public:
  int deleteAndEarn(vector<int> &nums) {
    int n = 10001;
    vector<int> values(n, 0);
    for (int num : nums)
      values[num] += num;
    int take = 0, skip = 0;
    for (int i = 0; i < n; i++) {
      int takei = skip + values[i];
      int skipi = max(skip, take);
      take = takei;
      skip = skipi;
    }
    return max(take, skip);
  }
};