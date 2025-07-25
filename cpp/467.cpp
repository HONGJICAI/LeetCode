class Solution {
    bool nextTo(char a, char b) {
        if (a == 'z')
            return b == 'a';
        return a + 1 == b;
    }
    int impl(string_view s) {
        int cnt[26] = {};
        int l = 0, r = 1;
        while (r <= s.size()) {
            if (l + 1 == r || nextTo(s[r - 2], s[r - 1])) {
                cnt[s[r - 1] - 'a'] = max(r - l, cnt[s[r - 1] - 'a']);
                ++r;
            } else {
                ++l;
            }
        }
        return ranges::fold_left(cnt, 0, plus{});
    }
public:
    int findSubstringInWraproundString(string s) {
        return impl(s);
    }
};
class SolutionTLE {
    bool nextTo(char a, char b) {
        if (a == 'z')
            return b == 'a';
        return a + 1 == b;
    }
    int count(unordered_set<string_view>& set) {
        unordered_set<string_view> result;
        for (auto sv: set) {
            for (int len = 2; len <= sv.size(); ++len) {
                for (int i = 0; i + len <= sv.size(); ++i) {
                    result.insert(sv.substr(i, len));
                }
            }
        }
        return result.size();
    }
    int impl(string_view s) {
        unordered_set<string_view> set;
        unordered_set<char> chSet {s.begin(), s.end()};
        char map[26] = {};
        int l = 0, r = 0;
        string_view lastSv;
        while (r <= s.size()) {
            if (l == r || l + 1 == r) {
                ++r;
            } else if (nextTo(s[r - 2], s[r - 1])) {
                lastSv = s.substr(l, r - l);
                if (r == s.size()) {                    
                    set.insert(lastSv);
                }
                ++r;
            } else {
                if (lastSv.size() > 0) {
                    set.insert(lastSv);
                    lastSv = "";
                    l = r - 1;
                } else {
                    ++l;
                }
            }
        }
        return chSet.size() + count(set);
    }
public:
    int findSubstringInWraproundString(string s) {
        return impl(s);
    }
};