class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int>wordmap;
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),[](char &ch)->char{
            switch(ch){
                case '!':case '?':case '\'':case ',':case ';':case '.':return ' ';
            }
            return tolower(ch);
        });
        unordered_set<string>bannedSet(banned.begin(),banned.end());
        stringstream ss(paragraph);
        string str;
        while(!ss.eof()){
            ss>>str;
            if(bannedSet.find(str)==bannedSet.end())
                ++wordmap[str];
        }
        return max_element(wordmap.begin(),wordmap.end(),[](const pair<const string,int>&a,const pair<const string,int>&b){
            return a.second<b.second;
        })->first;
    }
};
