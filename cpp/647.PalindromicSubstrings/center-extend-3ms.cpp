class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        for (int i=0; i<s.size(); i++) {
            extendPalindrom(s, i, i);
            extendPalindrom(s, i, i+1);
        }
        return count;
    }
    void extendPalindrom(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++; left--, right++;
        }
    }
};
