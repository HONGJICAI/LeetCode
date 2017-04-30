class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int>s;
        s.insert(1);
        auto it=s.begin();
        for(int i=1;i<n;++i,++it){
            s.insert(*it*2);
            s.insert(*it*3);
            s.insert(*it*5);
        }
        return *it;
    }
};
