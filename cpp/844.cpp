class Solution {
    string process(string& s) {
        string ret;
        for (auto ch: s) {
            if (ch == '#') {
                if (ret.size() > 0) ret.pop_back();
            }
            else ret += ch;
        }
        return ret;
    }
public:
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};