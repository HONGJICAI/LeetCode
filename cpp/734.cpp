// hashmap.cpp
class Solution {
public:
  bool areSentencesSimilar(vector<string> &words1, vector<string> &words2,
                           vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size())
      return false;
    unordered_map<string, unordered_set<string>> hashmap;
    for (auto &p : pairs) {
      hashmap[p.first].insert(p.second);
      hashmap[p.second].insert(p.first);
    }
    for (int i = 0; i < words1.size(); ++i)
      if (hashmap[words1[i]].find(words2[i]) == hashmap[words1[i]].end() &&
          words1[i] != words2[i])
        return false;
    return true;
  }
};
