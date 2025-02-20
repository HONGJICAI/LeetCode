// cleanerCode.cpp
class Solution {
public:
  int compress(vector<char> &chars) {
    int anchor = 0, write = 0;
    for (int read = 0; read < chars.size(); read++) {
      if (read + 1 == chars.size() || chars[read + 1] != chars[read]) {
        chars[write++] = chars[anchor];
        if (read > anchor) {
          string num = to_string(read - anchor + 1);
          memcpy(&chars[write], &num[0], num.size());
          write += num.size();
        }
        anchor = read + 1;
      }
    }
    return write;
  }
};
// singleScan.cpp
class Solution2 {
public:
  int compress(vector<char> &chars) {
    int res = 0;
    int count = 1;
    char last = chars[0];
    for (int i = 1; i < chars.size(); ++i) {
      if (chars[i] == last)
        ++count;
      else {
        chars[res++] = last;
        if (count > 1) {
          string num = to_string(count);
          memcpy(&chars[res], &num[0], num.size());
          res += num.size();
        }
        last = chars[i];
        count = 1;
      }
    }
    chars[res++] = last;
    if (count > 1) {
      string num = to_string(count);
      memcpy(&chars[res], &num[0], num.size());
      res += num.size();
    }
    return res;
  }
};
