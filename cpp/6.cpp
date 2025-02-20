// simple.cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        auto strings = vector<string>(numRows);
        for (int i = 0, j = 0, direct = 1; j < s.size(); i += direct) {
            strings[i] += s[j++];
            if (i == 0)
                direct = 1;
            else if (i == numRows - 1)
                direct = -1;
        }
        return accumulate(strings.begin(), strings.end(), string());
    }
};