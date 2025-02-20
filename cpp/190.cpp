// onepass-3ms.cpp
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    n = (n << 16) | (n >> 16);
    n = ((n << 8) & 0xff00ff00) | ((n >> 8) & 0x00ff00ff);
    n = ((n << 4) & 0xf0f0f0f0) | ((n >> 4) & 0x0f0f0f0f);
    n = ((n << 2) & 0xcccccccc) | ((n >> 2) & 0x33333333);
    n = ((n << 1) & 0xaaaaaaaa) | ((n >> 1) & 0x55555555);
    return n;
  }
};
