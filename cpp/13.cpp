class Solution {
    static unordered_map<char, int> hash;

public:
    int romanToInt(string s) {
        vector<int> st;
        for (auto c : s) {
            auto n = hash[c];
            if (st.empty() || st.back() >= n) {
                st.push_back(n);
            } else {
                int res = 0;
                while (st.size() && st.back() < n) {
                    res += st.back();
                    st.pop_back();
                }
                n -= res;
                st.push_back(n);
            }
        }
        return accumulate(st.begin(), st.end(), 0);
    }
};

unordered_map<char, int> Solution::hash = {{'I', 1},   {'V', 5},   {'X', 10},
                                           {'L', 50},  {'C', 100}, {'D', 500},
                                           {'M', 1000}};