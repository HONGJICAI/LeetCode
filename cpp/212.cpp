class Solution {
    struct Trie {
        int idx;
        Trie* parent = nullptr;
        Trie* children[26] = {};
        bool word = false;
        int childrenCnt = 0;
        Trie(int idx, Trie* parent): idx(idx), parent(parent) {}
        Trie() {}
    } root;
    void insert(auto& word) {
        auto p = &root;
        for (auto ch: word) {
            if (!p->children[ch-'a']) {
                p->children[ch-'a'] = new Trie(ch - 'a', p);
                ++p->childrenCnt;
            }
            p = p->children[ch-'a'];
        }
        p->word = true;
    }
    void tryErase(Trie* p) {
        p->word = false;
        while (p && !p->word && p->childrenCnt == 0 && p->parent) {
            auto top = p->parent;
            top->children[p->idx] = nullptr;
            --top->childrenCnt;
            delete top->children[p->idx];
            p = top;
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto& word: words)
            insert(word);
        vector<string> ret;
        string cur;
        function<void(int, int, Trie*)> dfs = [&](int i, int j, Trie* node) {
            auto ch = board[i][j];
            if (ch == '.') return;
            node = node->children[ch - 'a'];
            if (!node) return;
            cur += ch;
            if (node->word) {
                ret.push_back(cur);
                tryErase(node);
            }
            board[i][j] = '.';
            if (i > 0)
                dfs(i-1, j, node);
            if (j > 0)
                dfs(i, j-1, node);
            if (i + 1 < board.size())
                dfs(i + 1, j, node);
            if (j + 1< board[0].size())
                dfs(i, j + 1, node);
            cur.pop_back();
            board[i][j] = ch;
        };
        for (int m = 0; m < board.size(); ++m) {
            for (int n = 0; n < board[0].size(); ++n) {
                dfs(m, n, &root);
            }
        }
        return ret;
    }
};