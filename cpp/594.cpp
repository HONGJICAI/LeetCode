// hash.cpp
class Solution {
public:
  int findLHS(vector<int> &nums) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i)
      map[nums[i]]++;
    int res = 0;
    for (auto it = map.begin(); it != map.end(); ++it) {
      auto it2 = map.find(it->first + 1);
      if (it2 != map.end())
        res = max(it->second + it2->second, res);
      it2 = map.find(it->first - 1);
      if (it2 != map.end())
        res = max(it->second + it2->second, res);
    }
    return res;
  }
};
