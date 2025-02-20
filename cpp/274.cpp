// OnTimeOnSpace.cpp
class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    vector<int> arr(n + 1, 0);
    for (auto num : citations)
      if (num >= n)
        arr[n] += 1;
      else
        arr[num] += 1;
    int total = 0;
    for (int i = 0; i <= n; ++i) {
      total += arr[n - i];
      if (total >= n - i)
        return n - i;
    }
    return 0;
  }
};
