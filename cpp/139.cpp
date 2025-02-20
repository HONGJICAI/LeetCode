// dp.cpp 0ms
class Solution {
  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0)
            return false;
        string_view sv = s;
        unordered_set<string_view> hashset(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i)
            for (int j = i - 1; j >= 0; --j)
                if (dp[j] &&
                    hashset.find(sv.substr(j, i - j)) != hashset.end()) {
                    dp[i] = true;
                    break;
                }
        return dp.back();
    }
};
// trie+dp.cpp 3ms
class Solution2 {
    struct trie {
        trie() : isWord(false) {}
        bool isWord;
        trie* children[26] = {};
    } root;
    void insert(string& word) {
        trie* p = &root;
        for (auto ch : word) {
            int offset = ch - 'a';
            if (p->children[offset] == nullptr)
                p->children[offset] = new trie();
            p = p->children[offset];
        }
        p->isWord = true;
    }
    bool search(string_view word) {
        trie* p = &root;
        for (auto ch : word) {
            int offset = ch - 'a';
            if (p->children[offset] == nullptr)
                return false;
            p = p->children[offset];
        }
        return p->isWord;
    }
    bool dp(string_view s) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && search(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }

  public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string& str : wordDict)
            insert(str);
        return dp(s);
    }
};
