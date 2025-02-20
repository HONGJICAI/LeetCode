// simple.cpp
class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    string temp;
    vector<string> res;
    int start = 0, i, j;
    bool star = false;
    for (i = 0; i < source.size(); ++i) {
      for (j = 0; j < source[i].size(); ++j) {
        if (!star && source[i][j] == '/' && j + 1 < source[i].size()) {
          if (source[i][j + 1] == '/')
            break;
          else if (source[i][j + 1] == '*') {
            star = true;
            temp += source[i].substr(start, j - start);
            ++j;
          }
        } else if (star && source[i][j] == '*' && j + 1 < source[i].size() &&
                   source[i][j + 1] == '/') {
          star = false;
          ++j;
          start = j + 1;
        }
      }
      if (!star) {
        temp += source[i].substr(start, j - start);
        if (temp.size())
          res.emplace_back(move(temp));
        start = 0;
      }
    }
    return res;
  }
};
