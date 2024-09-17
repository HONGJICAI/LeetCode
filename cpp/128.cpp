// hashmap.cpp
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int maxLen = 0;
        for (auto num : nums) {
            if (hashmap.find(num) != hashmap.end())
                continue;
            auto left = hashmap.find(num - 1);
            auto right = hashmap.find(num + 1);
            int l = left == hashmap.end() ? 0 : left->second;
            int r = right == hashmap.end() ? 0 : right->second;
            int len = 1 + l + r;
            hashmap[num] = hashmap[num - l] = hashmap[num + r] = len;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
