// simple.cpp
class StringIterator {
  vector<pair<int, int>> res;
  int off;

public:
  StringIterator(string compressedString) {
    stringstream ss(compressedString);
    char ch;
    int val;
    while (!ss.eof()) {
      ss >> ch;
      ss >> val;
      res.push_back(pair<int, int>(ch, val));
    }
    off = 0;
  }

  char next() {
    if (off < res.size()) {
      char ch = res[off].first;
      off += (--res[off].second == 0);
      return ch;
    }
    return ' ';
  }

  bool hasNext() { return off < res.size(); }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
