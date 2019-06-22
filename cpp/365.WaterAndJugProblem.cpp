class Solution {
//Runtime: 984 ms, faster than 5.08% of C++ online submissions for Water and Jug Problem.
//Memory Usage: 152.6 MB, less than 5.31% of C++ online submissions for Water and Jug Problem.
public:
    bool canMeasureWater(int x, int y, int z) {
        array<function<void(int&,int&)>,6>ops={
            [&](int &a,int &){
                a=x;
            },
            [&](int &,int &b){
                b=y;
            },
            [&](int &a,int &){
                a=0;
            },
            [&](int &,int &b){
                b=0;
            },
            [&](int &a,int &b){
                auto diff=min(y-b,a);
                a-=diff;
                b+=diff;
            },
            [&](int &a,int &b){
                auto diff=min(x-a,b);
                a+=diff;
                b-=diff;
            }
        };
        unordered_set<long long>seen{0};
        deque<pair<int,int>> dq{{0,0}};
        while(dq.size()){
            for(auto &op:ops){
                auto [a,b]=dq.front();
                op(a,b);
                if(a==z or b==z or a+b==z)
                    return true;
                auto [it,ok]=seen.insert(((long long)a<<32)+b);
                if(ok)
                    dq.push_back({a,b});
            }
            dq.pop_front();
        }
        return false;
    }
};