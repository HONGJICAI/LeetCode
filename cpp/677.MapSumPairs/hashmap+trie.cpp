class MapSum {
    struct trie_node{
        trie_node *children[26];
        int val;
        trie_node(){
            memset(this,0,sizeof(trie_node));
        }
    }root;
    unordered_map<string,int>words;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto word=words.find(key);
        if(word!=words.end())
            val=val-word->second;
        words[key]=val;
        trie_node *p=&root;
        for(char ch:key){
            if(!p->children[ch-'a'])
                p->children[ch-'a']=new trie_node();
            p=p->children[ch-'a'];
            p->val+=val;
        }
    }
    
    int sum(string prefix) {
        trie_node *p=&root,*child;
        int i;
        for(i=0;i<prefix.size();++i){
            child=p->children[prefix[i]-'a'];
            if(!child)
                return 0;
            p=child;
        }
        return p->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
