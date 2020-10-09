class SolutionA { // 15ms
public:
  int reverse(int x) {
    long long value = 0;
    bool neg = x >= 0 ? 0 : 1;
    x = abs(x);
    while (x > 0) {
      value = value * 10 + x % 10;
      x /= 10;
    }
    value = neg == 0 ? value : -value;
    if (value < (int)0x80000000 || value > (int)0x7fffffff)
      return 0;
    return value;
  }
};
class SolutionB { // 0ms 100%
public:
  int reverse(int x) {
    auto s = to_string(x < 0 ? -(long long)x : x);
    auto val = stoll(string{s.rbegin(), s.rend()});
    val = x < 0 ? -val : val;
    return (val > 2147483647ll || val < -2147483648ll) ? 0 : val;
  }
};