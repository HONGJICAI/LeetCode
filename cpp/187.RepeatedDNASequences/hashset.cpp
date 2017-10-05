class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>hashset,res;
        for(int i=0;i<=(int)s.size()-10;++i){
            string str=s.substr(i,10);
            if(hashset.find(str)!=hashset.end())
                res.insert(str);
            else
                hashset.insert(str);
        }
        return vector<string>(res.begin(),res.end());
    }
};
