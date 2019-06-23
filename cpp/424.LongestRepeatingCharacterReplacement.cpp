class Solution {
//Runtime: 20 ms, faster than 41.40% of C++ online submissions for Longest Repeating Character Replacement.
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        vector<int>m(26);
        while (j < s.size()) {
            m[s[j++]-'A']++;
            if (j-i - *max_element(begin(m),end(m)) > k)
                m[s[i++]-'A']--;
        }
        return j - i;
    }
};