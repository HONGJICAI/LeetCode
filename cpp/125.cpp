// onepass-12ms.cpp
class Solution {
  public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalphanumeric(s[i]))
                ++i;
            while (j >= i && !isalphanumeric(s[j]))
                --j;
            if (i >= j)
                return 1;
            if ((s[i] == s[j] || s[i] - 'a' + 'A' == s[j] ||
                 s[i] - 'A' + 'a' == s[j]) &&
                isalphanumeric(s[i]) == isalphanumeric(s[j])) {
                ++i;
                --j;
            } else
                return 0;
        }
        return 1;
    }
    int isalphanumeric(char ch) {
        if (ch >= '0' && ch <= '9')
            return 1;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            return 2;
        return 0;
    }
};
class Solution2 {
  public:
    bool isPalindrome(string s) {
        string filtered;
        copy_if(s.begin(), s.end(), back_inserter(filtered), [](char c) {
            return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' ||
                   c >= '0' && c <= '9';
        });
        transform(
            filtered.begin(), filtered.end(), filtered.begin(),
            [](char c) { return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c; });
        return equal(filtered.begin(), filtered.begin() + filtered.size() / 2,
                     filtered.rbegin());
    }
};