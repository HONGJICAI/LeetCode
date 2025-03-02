// hash+bettersort+102ms.cpp
class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string> &paths) {
    unordered_map<string, int> hashmap;
    stringstream ss;
    string path, filename, content;
    vector<vector<string>> res;
    for (string str : paths) {
      ss << str;
      ss >> path;
      while (!ss.eof()) {
        ss >> filename;
        int left = filename.find("("), right = filename.find(")");
        content = filename.substr(left, right - left);
        // filename=filename.substr(0,left);
        if (hashmap.find(content) == hashmap.end()) {
          hashmap[content] = res.size();
          res.push_back(
              vector<string>(1, path + "/" + filename.substr(0, left)));
        } else
          res[hashmap[content]].emplace_back(path + "/" +
                                             filename.substr(0, left));
      }
      ss.clear();
    }
    int i = 0, j = res.size() - 1;
    while (i <= j) {
      while (i <= j && res[i].size() != 1)
        ++i;
      while (i <= j && res[j].size() == 1)
        --j;
      if (i <= j)
        res[i++] = res[j--];
    }
    res.resize(j + 1);
    return res;
  }
};
// hash+sort+96ms.cpp
class Solution2 {
public:
  vector<vector<string>> findDuplicate(vector<string> &paths) {
    unordered_map<string, int> hashmap;
    stringstream ss;
    string path, filename, content;
    vector<vector<string>> res;
    for (string str : paths) {
      ss << str;
      ss >> path;
      while (!ss.eof()) {
        ss >> filename;
        int left = filename.find("("), right = filename.find(")");
        content = filename.substr(left, right - left);
        filename = filename.substr(0, left);
        if (hashmap.find(content) == hashmap.end()) {
          hashmap[content] = res.size();
          res.push_back(vector<string>(1, path + "/" + filename));
        } else
          res[hashmap[content]].emplace_back(path + "/" + filename);
      }
      ss.clear();
    }
    sort(res.begin(), res.end(), [](vector<string> &a, vector<string> &b) {
      return a.size() > b.size();
    });
    int i;
    for (i = res.size() - 1; i >= 0 && res[i].size() == 1; --i)
      ;
    if (i >= -1)
      res.resize(i + 1);
    return res;
  }
};
