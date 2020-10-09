// sort.cpp
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> s;
    string res;
    for (int i = 0; i < nums.size(); ++i)
      s.push_back(to_string(nums[i]));
    sort(s.begin(), s.end(), [](const string &a, const string &b) {
      string aa = a + b, bb = b + a;
      for (int i = 0; i < aa.size(); i++)
        if (aa[i] != bb[i])
          return aa[i] > bb[i];
      return false;
    });
    for (int i = 0; i < s.size(); ++i)
      res += s[i];
    return res.find_first_not_of("0") == string::npos ? "0" : res;
  }
};
