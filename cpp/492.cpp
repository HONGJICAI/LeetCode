// sqrt-3ms.cpp
class Solution {
public:
  vector<int> constructRectangle(int area) {
    vector<int> result(2);
    int max_wide = 0;
    for (int i = 1; i * i <= area; ++i)
      if (area % i == 0)
        max_wide = i;
    result[0] = area / max_wide;
    result[1] = max_wide;
    return result;
  }
};
