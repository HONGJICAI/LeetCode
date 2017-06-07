class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n=points.size(),count=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(j==i)continue;
                else
                    for(int k=0;k<n;++k)
                        if(k==i||k==j)continue;
                        else if(dist(i,j,points)==dist(i,k,points))
                            count++;
        return count;
    }
    int dist(int i,int j,vector<pair<int, int>>& points){
        int x=points[i].first-points[j].first;
        int y=points[i].second-points[j].second;
        return x*x+y*y;
    }
};
