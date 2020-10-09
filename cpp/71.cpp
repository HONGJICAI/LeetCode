// vector.cpp
class Solution {
public:
  string simplifyPath(string path) {
    stringstream ss(path);
    string str, res;
    vector<string> st;
    while (getline(ss, str, '/'))
      if (str == ".." && !st.empty())
        st.pop_back();
      else if (str == "." || str == "")
        ;
      else if (str != "..")
        st.push_back(str);
    for (int i = 0; i < st.size(); ++i)
      res += "/" + st[i];
    return res == "" ? "/" : res;
  }
};
