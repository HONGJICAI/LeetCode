// bruteForce.cpp
class Solution {
public:
  int strStr(string haystack, string needle) {
    for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++i)
      for (int j = 0;; ++j) {
        if (j == needle.size())
          return i;
        if (needle[j] != haystack[i + j])
          break;
      }
    return -1;
  }
};
class Solution2 { // my fake kmp
    vector<int> getNext(string p) {
        vector<int> res(p.size(), 0);
        for(int i = 0, j = 1; j < p.size();) {// i for suffix and j for prefix
            if (p[i] == p[j]) {
                if (res[j] < i + 1) {
                    res[j] = i + 1;
                }
                ++i;
                ++j;
            } else {
                j = j - i + 1;
                i = 0;
            }
        }
        return res;
    }
public:
    int strStr(string haystack, string needle) {
        auto next = getNext(needle);
        for(int i = 0, j = 0; i < haystack.size(); ++i) {
            bool match = false;
            bool fail = false;
            for(; j < needle.size();) {
                if (haystack[i] == needle[j]) {
                    match = true;
                    ++i;
                    ++j;
                } else {
                    fail = true;
                    int n = j > 0 ? next[j-1] : 0;
                    j = n;
                    if(j==0) break;
                }
            }
            if(j == needle.size())
                return i - j;
            if (match && fail) {
                --i;
            }
        }
        return -1;
    }
};