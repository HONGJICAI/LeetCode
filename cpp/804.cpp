// hashset.cpp
class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    const static string morse[26] = {
        ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
        ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
        "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
    unordered_set<string> res;
    for (auto &str : words) {
      string s;
      for (auto ch : str)
        s += morse[ch - 'a'];
      res.insert(s);
    }
    return res.size();
  }
};
