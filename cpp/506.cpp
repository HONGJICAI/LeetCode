// simpleidea.cpp
class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &nums) {
    struct tri {
      int score;
      int index;
      string str;
      tri(){};
      tri(int score, int index) : score(score), index(index), str(""){};
    };
    int n = nums.size();
    vector<tri> arr(n);
    for (int i = 0; i < n; ++i)
      arr[i] = tri(nums[i], i);
    sort(arr.begin(), arr.end(),
         [](tri a, tri b) { return a.score > b.score; });
    if (n)
      arr[0].str = "Gold Medal";
    if (n > 1)
      arr[1].str = "Silver Medal";
    if (n > 2)
      arr[2].str = "Bronze Medal";
    for (int i = 3; i < n; ++i)
      arr[i].str = to_string(i + 1);
    sort(arr.begin(), arr.end(),
         [](tri a, tri b) { return a.index < b.index; });
    vector<string> result(n);
    for (int i = 0; i < n; ++i)
      result[i] = arr[i].str;
    return result;
  }
};
