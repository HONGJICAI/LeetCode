// BruteForce.cpp
class Solution {
public:
  string replaceWords(vector<string> &dict, string sentence) {
    stringstream ss(sentence);
    vector<string> res;
    string word;
    while (!ss.eof()) {
      ss >> word;
      res.emplace_back(word);
    }
    for (auto d : dict)
      for (auto &w : res)
        if (w.find(d) == 0)
          w = d;
    word = "";
    for (auto w : res)
      word += w + " ";
    word.pop_back();
    return word;
  }
};
// usingTrie.cpp
class Solution {
  struct trie {
    trie() : isWord(false) {
      for (int i = 0; i < 26; ++i)
        arr[i] = nullptr;
    }
    bool isWord;
    trie *arr[26];
  } root;
  void buildTrie(vector<string> &dict) {
    for (auto &str : dict)
      buildTrie(str);
  }
  void buildTrie(string &word) {
    trie *p = &root;
    for (auto ch : word) {
      int offset = ch >= 'a' && ch <= 'z' ? ch - 'a' : ch - 'A';
      if (p->arr[offset] == nullptr)
        p->arr[offset] = new trie();
      p = p->arr[offset];
    }
    p->isWord = true;
  }
  int replace(string &word) {
    trie *p = &root;
    int length = 0;
    for (auto ch : word) {
      int offset = ch >= 'a' && ch <= 'z' ? ch - 'a' : ch - 'A';
      if (p->arr[offset] == nullptr)
        return INT_MAX;
      ++length;
      p = p->arr[offset];
      if (p->isWord)
        return length;
    }
    return INT_MAX;
  }

public:
  string replaceWords(vector<string> &dict, string sentence) {
    stringstream ss(sentence);
    string word, res;
    buildTrie(dict);
    while (!ss.eof()) {
      ss >> word;
      res += word.substr(0, replace(word)) + " ";
    }
    res.pop_back();
    return res;
  }
};
