// hashmap+deque.cpp
class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    deque<int> res(nums.size(), 0);
    int count = 0, len = 0;
    for (int i = 0; i < nums.size(); ++i)
      res[i] = count += nums[i] == 0 ? 1 : -1;
    res.push_front(0);
    unordered_map<int, int> hashmap;
    for (int i = 0; i < res.size(); ++i) {
      auto it = hashmap.find(res[i]);
      if (it == hashmap.end())
        hashmap[res[i]] = i;
      else
        len = max(len, i - it->second);
    }
    return len;
  }
};
