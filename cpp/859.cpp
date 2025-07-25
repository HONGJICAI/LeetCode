class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        unordered_map<char, int> m1, m2;
        bool moreThanTwo;
        int differCnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            moreThanTwo |= ++m1[s[i]] > 1;
            ++m2[goal[i]];
            differCnt += s[i] != goal[i];
        }
        if (m1 == m2) return s == goal ? moreThanTwo : (differCnt == 2);
        return false;
    }
};