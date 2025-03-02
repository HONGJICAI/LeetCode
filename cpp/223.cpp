// decreaseoverlap.cpp
class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int sum = (C - A) * (D - B) + (G - E) * (H - F);
    int left = max(A, E);
    int right = min(C, G);
    int up = min(D, H);
    int down = max(B, F);
    if (up > down && right > left)
      sum -= (up - down) * (right - left);
    return sum;
  }
};
