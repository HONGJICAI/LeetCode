class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,int>p;
        unordered_map<string,int>s;
        istringstream in(str);
        vector<string>sv;
        string ss;
        while(in>>ss)
            sv.push_back(ss);
        if(pattern.size()!=sv.size())return 0;
        for(int i=0;i<pattern.size();++i){
            if( p[pattern[i]] != s[sv[i]])
                return 0;
            p[pattern[i]]=i+1;
            s[sv[i]]=i+1;
        }
        return 1;
    }
};
