class Solution { // 8ms  99.37%
public:
  vector<string> commonChars(vector<string> &A) {
    vector<int> arr(26, numeric_limits<int>::max());
    vector<string> res;
    for (auto &s : A) {
      array<int, 26> cnt = {};
      for (auto c : s)
        ++cnt[c - 'a'];
      for (auto i = 0; i < 26; ++i)
        arr[i] = min(arr[i], cnt[i]);
    }
    for (auto i = 0; i < 26; ++i)
      while (arr[i] != numeric_limits<int>::max() && arr[i]-- > 0)
        res.push_back(string(1, i + 'a'));
    return res;
  }
};