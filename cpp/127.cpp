// bfs.cpp
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_map<int, char> map;
    int len = 1, n = beginWord.size();
    queue<string> qe;
    qe.push(beginWord);
    unordered_set<string> wordlist(wordList.begin(), wordList.end());
    string temp;
    while (!qe.empty()) {
      int times = qe.size();
      for (int k = 0; k < times; ++k) {
        temp = qe.front();
        if (temp == endWord)
          return len;
        qe.pop();
        for (int i = 0; i < n; ++i) {
          char ch = temp[i];
          for (int j = 0; j < 26; ++j) {
            temp[i] = 'a' + j;
            if (wordlist.find(temp) != wordlist.end()) {
              qe.push(temp);
              wordlist.erase(temp);
            }
          }
          temp[i] = ch;
        }
      }
      len++;
    }
    return 0;
  }
};
