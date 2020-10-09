class Solution {
  // Runtime: 120 ms, faster than 51.55% of C++ online submissions for Can I
  // Win. Memory Usage: 25 MB, less than 49.12% of C++ online submissions for
  // Can I Win.
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    unordered_map<int, bool> m;
    if (maxChoosableInteger >= desiredTotal)
      return true;
    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
      return false;
    function<bool(int, int)> canWin = [&](int target, int visited) {
      if (auto it = m.find(visited); it != m.end())
        return it->second;
      for (int i = 1; i <= maxChoosableInteger; i++) {
        int mask = (1 << i);
        if ((mask & visited) == 0 &&
            (i >= target or not canWin(target - i, mask | visited)))
          return m[visited] = true;
      }
      return m[visited] = false;
    };
    return canWin(desiredTotal, 0);
  }
};