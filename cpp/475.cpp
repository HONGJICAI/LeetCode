class Solution {
  // Runtime: 80 ms, faster than 76.32% of C++ online submissions for Heaters.
  // Memory Usage: 11.6 MB, less than 17.92% of C++ online submissions for
  // Heaters.
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(begin(houses), end(houses));
    sort(begin(heaters), end(heaters));
    vector<int> res(houses.size(), INT_MAX);
    // For each house, calculate distance to nearest RHS heater
    for (int i = 0, h = 0; i < houses.size() && h < heaters.size();)
      if (houses[i] <= heaters[h])
        res[i++] = heaters[h] - houses[i];
      else
        h++;
    // For each house, calculate distance to nearest LHS heater
    for (int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;)
      if (houses[i] >= heaters[h])
        res[i--] = min(res[i], houses[i] - heaters[h]);
      else
        h--;
    return *max_element(begin(res), end(res));
  }
};
class Solution2 {
  // Runtime: 80 ms, faster than 76.32% of C++ online submissions for Heaters.
  // Memory Usage: 11.7 MB, less than 9.44% of C++ online submissions for
  // Heaters.
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(begin(houses), end(houses));
    sort(begin(heaters), end(heaters));
    vector<int> res(houses.size(), INT_MAX);
    // For each house, calculate distance to nearest RHS heater
    for (auto i = begin(houses), h = begin(heaters), r = begin(res);
         i != end(houses) and h != end(heaters);)
      if (*i <= *h)
        *r++ = *h - *i++;
      else
        ++h;
    // For each house, calculate distance to nearest LHS heater
    for (auto i = rbegin(houses), h = rbegin(heaters), r = rbegin(res);
         i != rend(houses) and h != rend(heaters);)
      if (*i >= *h)
        *r++ = min(*r, *i++ - *h);
      else
        ++h;
    return *max_element(begin(res), end(res));
  }
};