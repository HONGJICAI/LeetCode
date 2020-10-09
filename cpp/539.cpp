// sort-19ms.cpp
class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    vector<int> arr(timePoints.size());
    for (int i = 0; i < timePoints.size(); ++i)
      arr[i] = ((timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0')) * 60 +
               (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
    sort(arr.begin(), arr.end());
    int min = arr[0] + 24 * 60 - arr[arr.size() - 1];
    for (int i = 1; i < arr.size(); ++i)
      min = min < arr[i] - arr[i - 1] ? min : arr[i] - arr[i - 1];
    return min;
  }
};
