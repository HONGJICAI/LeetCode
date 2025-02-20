class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        string ret;
        for (int charN = 0; charN < strs[0].size(); ++charN) {
            for (int wordN = 0; wordN < strs.size(); ++wordN) {
                if (strs[wordN][charN] != strs[0][charN]) {
                    return ret;
                }
            }
            ret += strs[0][charN];
        }
        return ret;
    }
};