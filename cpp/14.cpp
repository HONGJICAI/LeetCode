class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        string ret;
        for (int charN = 0; charN < strs[0].size(); ++charN) {
            for (int wordN = 1; wordN < strs.size(); ++wordN) {
                if (strs[wordN][charN] != strs[0][charN]) {
                    return ret;
                }
            }
            ret += strs[0][charN];
        }
        return ret;
    }
};
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0 || strs[0].size() == 0)
            return "";
        string pre = "";
        for (int j = 0; j < strs[0].size(); ++j) {
            char ch = strs[0][j];
            if (all_of(strs.begin() + 1, strs.end(), [j, ch](const string& s) {
                    return s.size() > j && s[j] == ch;
                })) {
                pre += ch;
            } else {
                break;
            }
        }
        return pre;
    }
};