// singleScan.cpp
class Solution {
public:
  int lengthLongestPath(string input) {
    stringstream ss(input);
    string str;
    vector<int> lens;
    int maxlen = 0, curtotal = 0;
    while (ss) {
      getline(ss, str);
      int tcount = 0;
      while (str[tcount] == '\t')
        ++tcount;
      int curlen = str.size() - tcount + 1;
      for (; tcount < lens.size(); lens.pop_back())
        curtotal -= lens.back();
      lens.push_back(curlen);
      curtotal += curlen;
      if (str.find('.') != string::npos)
        maxlen = max(maxlen, curtotal);
    }
    return maxlen == 0 ? 0 : maxlen - 1;
  }
};
