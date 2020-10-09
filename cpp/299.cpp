class Solution {
  // Runtime: 4 ms, faster than 97.05% of C++ online submissions for Bulls and
  // Cows. Memory Usage: 9 MB, less than 33.22% of C++ online submissions for
  // Bulls and Cows.
public:
  string getHint(string secret, string guess) {
    int A = 0, B = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < secret.size(); ++i)
      if (secret[i] == guess[i])
        ++A;
      else
        ++m[secret[i]];
    for (int i = 0; i < secret.size(); ++i)
      if (secret[i] != guess[i]) {
        if (auto it = m.find(guess[i]); it != end(m)) {
          ++B;
          if (--it->second == 0)
            m.erase(it);
        }
      }
    return to_string(A) + "A" + to_string(B) + "B";
  }
};