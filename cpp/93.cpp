// dfs.cpp
class Solution {
    vector<string> res;
    void dfs(string s, string_view t, int part) {
        if (part == 4) {
            if (t == "")
                res.push_back(s);
            return;
        }
        if (part > 0)
            s += ".";
        for (int i = 1, val; i <= 3 && i <= t.size(); ++i) {
            if (i > 1 && t[0] == '0')
                break;
            string_view temp = t.substr(0, i);
            from_chars(temp.data(), temp.data() + temp.size(), val);
            if (val > 255)
                break;
            dfs(s + string(temp), t.substr(i), part + 1); // string + string_view require c++26
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        dfs("", s, 0);
        return res;
    }
};
