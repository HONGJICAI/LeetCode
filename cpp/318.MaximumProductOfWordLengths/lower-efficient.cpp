class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len=0;
        for(int i=0;i<words.size();++i){
            unordered_set<char>hashset(words[i].begin(),words[i].end());
            for(int j=i+1;j<words.size();++j){
                bool withoutCommon=true;
                for(int k=0;k<words[j].size();++k)
                    if(hashset.find(words[j][k])!=hashset.end()){
                        withoutCommon=false;
                        break;
                    }
                len=withoutCommon?max(len,(int)(words[i].size()*words[j].size())):len;
            }
        }
        return len;
    }
};
