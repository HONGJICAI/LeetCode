// hashset.cpp
class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string_view> hashset, res;
        for (int i = 0; i <= (int)s.size() - 10; ++i) {
            auto str = string_view(s).substr(i, 10);
            if (hashset.find(str) != hashset.end())
                res.insert(str);
            else
                hashset.insert(str);
        }
        return {res.begin(), res.end()};
    }
};