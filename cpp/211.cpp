// sometimesBetter.cpp
class WordDictionary {
  unordered_map<int, unordered_set<string>> words;

  bool isEqual(string &a, string &b) {
    for (int i = 0; i < a.size(); i++) {
      if (b[i] == '.')
        continue;
      if (a[i] != b[i])
        return false;
    }
    return true;
  }

public:
  /** Initialize your data structure here. */
  WordDictionary() {}

  /** Adds a word into the data structure. */
  void addWord(string word) { words[word.size()].insert(word); }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) {
    if (words[word.size()].find(word) != words[word.size()].end())
      return true;
    for (auto s : words[word.size()]) {
      if (isEqual(s, word))
        return true;
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
// trie.cpp
class WordDictionary2 {
  struct trie {
    trie() : isWord(false) { memset(this->children, 0, sizeof(children)); }
    bool isWord;
    trie *children[26];
  } root;

public:
  /** Initialize your data structure here. */
  WordDictionary2() {}

  /** Adds a word into the data structure. */
  void addWord(string word) {
    trie *p = &root;
    for (auto ch : word) {
      int offset = ch - 'a';
      if (p->children[offset] == nullptr)
        p->children[offset] = new trie();
      p = p->children[offset];
    }
    p->isWord = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) {
    trie *p = &root;
    return helper(word, 0, p);
  }
  bool helper(string &word, int index, trie *p) {
    if (p == nullptr)
      return false;
    if (index == word.size())
      return p->isWord;
    if (word[index] == '.') {
      for (int i = 0; i < 26; ++i)
        if (helper(word, index + 1, p->children[i]))
          return true;
      return false;
    }
    return helper(word, index + 1, p->children[word[index] - 'a']);
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
