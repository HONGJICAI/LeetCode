// ugly.cpp
class Solution {
public:
  string intToRoman(int num) {
    string res = "";
    unordered_map<int, char> hash = {{1, 'I'},   {5, 'V'},   {10, 'X'},
                                     {50, 'L'},  {100, 'C'}, {500, 'D'},
                                     {1000, 'M'}};
    for (int base = 1000, r; base; base /= 10) {
      r = num / base;
      if (r) {
        switch (r) {
        case 4:
          res = res + hash[base] + hash[base * 5];
          break;
        case 9:
          res = res + hash[base] + hash[base * 10];
          break;
        default:
          if (r >= 5)
            res.append(1, hash[base * 5]);
          res.append(r % 5, hash[base]);
        }
        num -= r * base;
      }
    }
    return res;
  }
};
