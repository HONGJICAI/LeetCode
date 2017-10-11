class MagicDictionary {   
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
    
    bool _search(string word) {
        trie *p=&root;
        for(auto ch:word){
            int offset=ch-'a';
            if( p->children[offset]==nullptr )
                return false;
            p=p->children[offset];
        }
        return p->isWord;
    }
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string &str:dict)
            insert(str);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(int i=0;i<word.size();++i){
            char old=word[i];
            for(char j='a';j<='z';++j){
                word[i]=j;
                if(j!=old&&_search(word))
                    return true;
            }
            word[i]=old;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
