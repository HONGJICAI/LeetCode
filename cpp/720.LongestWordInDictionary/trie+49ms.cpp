class Solution {
    struct trie{
        trie *children[26]={};
    }root;
public:
    /** Inserts a word into the trie. */
    bool insert(string &word) {
        trie *p=&root;
        for(int i=0;i<word.size();++i){
            int offset=word[i]-'a';
            if( p->children[offset]==nullptr)
                if(i==word.size()-1)
                    p->children[offset]=new trie();
                else
                    return false;
            p=p->children[offset];
        }
        return true;
    }
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string res="";
        for(auto &word:words)
            if(insert(word)&&(word.size()>res.size()||(word.size()==res.size()&&word<res)))
               res=word;
        return res;
    }
};
