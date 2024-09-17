// simple.cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        auto strings = vector<string>(numRows);
        for(int i = 0, j = 0, direct = 1; j < s.size();) {
            strings[i] += s[j++];
            if(i == 0) direct = 1;
            if(i == numRows - 1) direct = -1;
            i += direct;
        }
        return accumulate(strings.begin(), strings.end(), string());
    }
};