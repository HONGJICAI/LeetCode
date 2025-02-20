class Solution { // Runtime: 20 ms, faster than 80.96% of C++ online submissions
                 // for Shortest Completing Word.
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    vector<int> cntlic(26, 0);
    for (auto ch : licensePlate)
      if (isalpha(ch))
        ++cntlic[tolower(ch) - 'a'];
    string res = "aaaaaaaaaaaaaaaa"; // the problem says max len is 15
    for (const auto &str : words) {
      if (str.size() > res.size())
        continue;
      vector<int> cnt = cntlic;
      for (const auto ch : str)
        --cnt[ch - 'a'];
      auto it = find_if(cnt.begin(), cnt.end(),
                        [](const int val) { return val > 0; });
      if (it == cnt.end() && str.length() < res.size())
        res = str;
    }
    return res;
  }
};
class Solution2 { // Runtime: 16 ms
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    vector<int> cntlic(26, 0);
    for (auto ch : licensePlate) {
      if (isalpha(ch)) {
        ++cntlic[tolower(ch) - 'a'];
      }
    }
    // auto minL = numeric_limits<size_t>::max();
    string res = "aaaaaaaaaaaaaaaa";
    for (const auto &str : words) {
      vector<int> cnt(26, 0);
      for (const auto ch : str) {
        ++cnt[ch - 'a'];
      }
      bool complete = true;
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] < cntlic[i]) {
          complete = false;
          break;
        }
      }
      if (complete && str.length() < res.size()) {
        res = str;
        // minL = str.length();
      }
    }

    return res;
  }
};