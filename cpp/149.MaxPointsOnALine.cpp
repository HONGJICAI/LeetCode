class Solution {
//Runtime: 12 ms Your runtime beats 92.52 % of cpp submissions
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        auto getKB=[](int x1,int y1,int x2,int y2){
            int y=y1-y2,x=x1-x2;
            int gcd=__gcd(y, x);
            y=y/gcd,x=x/gcd;
            return (((long long)*reinterpret_cast<unsigned int*>(&y))<<32ll)|(*reinterpret_cast<unsigned int*>(&x));
        };
        int ret=0;
        for(int i=0;i<points.size();++i){
            unordered_map<long long,int>hash;
            int duplicate=0;
            int vertical=0;
            int res=0;
            for(int j=0;j<points.size();++j){
                if(i==j)
                    continue;
                else if(points[i][0]==points[j][0] and points[i][1]==points[j][1])
                    ++duplicate;
                else if(points[i][0]==points[j][0])
                    res=max(res,++vertical);
                else
                    res=max(res,++hash[getKB(points[i][0],points[i][1],points[j][0],points[j][1])]);
            }
            ret=max(ret,res+1+duplicate);
        }
        return ret;
    }
};