// usingVector.cpp
class Solution {
public:
  int calPoints(vector<string> &ops) {
    vector<int> st;
    int res = 0;
    for (auto &str : ops) {
      if (str == "C") {
        res -= st.back();
        st.pop_back();
        continue;
      } else if (str == "D")
        st.push_back(st.back() * 2);
      else if (str == "+")
        st.push_back(st.back() + st[st.size() - 2]);
      else
        st.push_back(stoi(str));
      res += st.back();
    }
    return res;
  }
};
