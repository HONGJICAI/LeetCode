class Solution {
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divisor
  // Game. Memory Usage: 8.6 MB, less than 12.27% of C++ online submissions for
  // Divisor Game.
public:
  bool divisorGame(int N) {
    vector<int> dp = {0, 0, 1, 0};
    dp.resize(N + 1);
    for (int i = 4; i <= N; ++i) {
      dp[i] = 0;
      for (int j = i / 2; j >= 1; --j) {
        if (i % j == 0 and dp[i - j] == 0) {
          dp[i] = 1;
          break;
        }
      }
    }
    return dp[N];
  }
};