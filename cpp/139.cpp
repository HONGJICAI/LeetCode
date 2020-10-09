// dp.cpp
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    if (wordDict.size() == 0)
      return false;
    unordered_set<string> hashset(wordDict.begin(), wordDict.end());
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); ++i)
      for (int j = i - 1; j >= 0; --j)
        if (dp[j] && hashset.find(s.substr(j, i - j)) != hashset.end()) {
          dp[i] = true;
          break;
        }
    return dp[s.size()];
  }
};
// trie+dfs-TLE.cpp
class Solution {
  struct trie {
    trie() : isWord(false) { memset(this, 0, sizeof(trie)); }
    bool isWord;
    trie *children[26];
  } root;
  void insert(string &word) {
    trie *p = &root;
    for (auto ch : word) {
      int offset = ch - 'a';
      if (p->children[offset] == nullptr)
        p->children[offset] = new trie();
      p = p->children[offset];
    }
    p->isWord = true;
  }
  bool search(string &word, int start) {
    trie *p = &root;
    for (auto ch : word) {
      int offset = ch - 'a';
      if (p->children[offset] == nullptr)
        return false;
      p = p->children[offset];
    }
    return p->isWord;
  }
  bool dfs(string &s, int index) {
    if (index == s.size())
      return true;
    trie *p = &root;
    for (; index < s.size(); ++index) {
      int offset = s[index] - 'a';
      if (p->children[offset] == nullptr)
        return false;
      p = p->children[offset];
      if (p->isWord && dfs(s, index + 1))
        return true;
    }
    return false;
  }

public:
  bool wordBreak(string s, vector<string> &wordDict) {
    for (string &str : wordDict)
      insert(str);
    return dfs(s, 0);
  }
};
