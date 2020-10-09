// better.cpp
class Solution {
public:
  bool isValidSerialization(string preorder) {
    stringstream ss(preorder);
    string str;
    int num = 0;
    while (!ss.eof()) {
      getline(ss, str, ',');
      num += str == "#" ? -1 : 1;
      if (num == -1)
        break;
    }
    return num == -1 && ss.eof();
  }
};
// dfs+stringstream.cpp
class Solution {
  bool dfs(vector<string> &arr, int &i) {
    if (i >= arr.size())
      return false;
    if (arr[i] == "#")
      return true;
    return dfs(arr, ++i) && dfs(arr, ++i);
  }

public:
  bool isValidSerialization(string preorder) {
    vector<string> arr;
    stringstream ss(preorder);
    string str;
    while (!ss.eof()) {
      getline(ss, str, ',');
      arr.emplace_back(str);
    }
    int i = 0;
    return dfs(arr, i) && i == arr.size() - 1;
  }
};
