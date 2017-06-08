class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,int>hashmap;
        stringstream ss;
        string path,filename,content;
        vector<vector<string>> res;
        for(string str:paths){
            ss<<str;
            ss>>path;
            while(!ss.eof()){
                ss>>filename;
                int left=filename.find("("),right=filename.find(")");
                content=filename.substr(left,right-left);
                filename=filename.substr(0,left);
                if(hashmap.find(content)==hashmap.end()){
                    hashmap[content]=res.size();
                    res.push_back(vector<string>(1,path+"/"+filename));
                }
                else
                    res[hashmap[content]].emplace_back(path+"/"+filename);
            }
            ss.clear();
        }
        sort(res.begin(),res.end(),[](vector<string>&a,vector<string>&b){return a.size()>b.size();});
        int i;
        for(i=res.size()-1;i>=0&&res[i].size()==1;--i);
        if(i>=-1)
            res.resize(i+1);
        return res;
    }
};
