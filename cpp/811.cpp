// hashmap.cpp
class Solution {
public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    unordered_map<string, int> hashmap;
    for (auto &str : cpdomains) {
      int i = 0, val;
      stringstream ss(str);
      ss >> val >> str;
      do {
        hashmap[str.substr(i)] += val;
      } while ((i = str.find('.', i) + 1) != string::npos + 1);
    }
    vector<string> res;
    for (auto &p : hashmap) {
      res.push_back(to_string(p.second) + " " + p.first);
    }
    return res;
  }
};
