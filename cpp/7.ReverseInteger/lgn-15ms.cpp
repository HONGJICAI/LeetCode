class Solution {
public:
    int reverse(int x) {
        long long value=0;
        bool neg=x>=0?0:1;
        x=abs(x);
        while(x>0){
            value=value*10+x%10;
            x/=10;
        }
        value= neg==0?value:-value;
        if(value<(int)0x80000000 || value> (int)0x7fffffff )
            return 0;
        return value;
    }
};
