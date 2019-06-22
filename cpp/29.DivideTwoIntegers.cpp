class Solution {
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
//Memory Usage: 8.2 MB, less than 47.58% of C++ online submissions for Divide Two Integers.
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)
            return 0x7fffffff;
        if(dividend==0)
            return 0;
        auto res = [](long long dividend,long long divisor)->long long{
            auto res=0ll;
            while(dividend>=divisor){
                auto level=1ll;
                for(;(divisor<<level)<dividend;++level);
                res+=1ll<<(level-1ll);
                dividend-=divisor<<(level-1ll);
            }
            return res;
        }(abs((long long)dividend),abs((long long)divisor))*((dividend>0 and divisor>0)or(dividend<0 and divisor<0)?1:-1);
        if(res>2147483647ll)
            return 0x7fffffff;
        if(res<-2147483648ll)
            return -2146483648;
        return res;
    }
};