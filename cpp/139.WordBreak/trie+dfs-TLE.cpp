class Solution {
    struct trie{
        trie():isWord(false){
            memset(this,0,sizeof(trie));
        }
        bool isWord;
        trie *children[26];
    }root;
    void insert(string &word) {
        trie *p=&root;
        for(auto ch:word){
            int offset=ch-'a';
            if( p->children[offset]==nullptr )
                p->children[offset]=new trie();
            p=p->children[offset];
        }
        p->isWord=true;
    }
    bool search(string &word,int start) {
        trie *p=&root;
        for(auto ch:word){
            int offset=ch-'a';
            if( p->children[offset]==nullptr )
                return false;
            p=p->children[offset];
        }
        return p->isWord;
    }
    bool dfs(string &s,int index){
        if(index==s.size())
            return true;
        trie *p=&root;
        for(;index<s.size();++index){
            int offset=s[index]-'a';
            if( p->children[offset]==nullptr )
                return false;
            p=p->children[offset];
            if(p->isWord&&dfs(s,index+1))
                return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &str:wordDict)
            insert(str);
        return dfs(s,0);
    }
};
