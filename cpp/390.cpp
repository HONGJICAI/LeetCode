class Solution {
  // Runtime: 8 ms, faster than 80.71% of C++ online submissions for Elimination
  // Game. Memory Usage: 8.3 MB, less than 36.46% of C++ online submissions for
  // Elimination Game.
public:
  int lastRemaining(int n) {
    function<int(int, bool)> dfs = [&dfs](int n, bool left) {
      if (n == 1)
        return 1;
      if (left)
        return 2 * dfs(n / 2, !left);
      else
        return (n % 2 ? 0 : -1) + 2 * dfs(n / 2, !left);
    };
    return dfs(n, true);
  }
};