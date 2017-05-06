class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>map;
        vector<vector<string>>res;
        for(int i=0,count=0;i<strs.size();++i){
            string newstr=strs[i];
            sort(newstr.begin(),newstr.end());
            auto it=map.find(newstr);
            if(it==map.end()){
                map[newstr]=count++;
                res.push_back(vector<string>(1,strs[i]));
            }
            else{
                res[it->second].push_back(strs[i]);
            }
        }
        return res;
    }
};
