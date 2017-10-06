class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len=0;
        vector<int>comp(words.size(),0);
        for(int i=0;i<words.size();++i){
            string &str=words[i];
            for(int j=0;j<str.size();++j)
                comp[i]|=1<<(str[j]-'a');
        }
        for(int i=0;i<words.size();++i)
            for(int j=i+1;j<words.size();++j)
                if( (comp[i]&comp[j])==0 )
                    len=max(len,(int)(words[i].size()*words[j].size()));
        return len;
    }
};
