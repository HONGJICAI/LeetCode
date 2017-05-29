class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>map;
        vector<string>res;
        for(int i=0;i<list1.size();++i)
            map[list1[i]]=i;
        int n=list2.size(),m=0x7fffffff;
        for(int i=0;i<n;++i){
            auto it=map.find(list2[i]);
            if(it!=map.end()){
                int sum=it->second+i;
                if(sum==m)
                    res.push_back(list2[i]);
                else if(sum<m){
                    res.assign(1,list2[i]);
                    m=sum;
                }
            }
        }
        return res;
    }
};
