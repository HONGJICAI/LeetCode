class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool hash[256] = {};
        int ret = 0, l = 0, r = 0;
        while (r < s.size()) {
            if (!hash[s[r]]) {
                ret = max(ret, r - l + 1);
                hash[s[r++]] = true;
            } else {
                hash[s[l++]] = false;
            }
        }
        return ret;
    }
};