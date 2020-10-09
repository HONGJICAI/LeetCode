class Solution { // 0ms iteration
public:
  int bitwiseComplement(int N) {
    if (!N)
      return 1;
    int res = 0, time = 0;
    while (N) {
      res += (!(N & 1)) << time++;
      N >>= 1;
    }
    return res;
  }
};