class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n=points.size(),count=0;
        unordered_map<int,int>map;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(j==i)continue;
                map[dist(points[i],points[j])]++;
            }
            for(auto it=map.begin();it!=map.end();++it)
                count+=(it->second)*(it->second-1);
            map.clear();
        }
        return count;
    }
    int dist(pair<int, int>&i,pair<int, int>&j){
        int x=i.first-j.first;
        int y=i.second-j.second;
        return x*x+y*y;
    }
};
