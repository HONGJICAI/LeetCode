class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n>10)
            n=0;
        int res=0;
        for(int i=0;i<n;++i){
            long long int r=9;
            for(int j=0;j<i;++j)
                r*=9-j;
            res+=r;
        }
        return res+1;
    }
};
