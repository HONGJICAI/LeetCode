// trie.cpp
class Trie {
  struct trie {
    trie() : isWord(false) { memset(this, 0, sizeof(trie)); }
    bool isWord;
    trie *children[26];
  } root;

public:
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    trie *p = &root;
    for (auto ch : word) {
      int offset = ch - 'a';
      if (p->children[offset] == nullptr)
        p->children[offset] = new trie();
      p = p->children[offset];
    }
    p->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    trie *p = &root;
    for (auto ch : word) {
      int offset = ch - 'a';
      if (p->children[offset] == nullptr)
        return false;
      p = p->children[offset];
    }
    return p->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    trie *p = &root;
    for (auto ch : prefix) {
      int offset = ch - 'a';
      if (p->children[offset] == nullptr)
        return false;
      p = p->children[offset];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
