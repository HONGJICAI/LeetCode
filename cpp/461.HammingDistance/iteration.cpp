class Solution {
public:
    int hammingDistance(int x, int y) {
        int result=x^y,sum=0;
        for(int i=0;i<32;i++,result>>=1)
            if(result%2==1)
                sum++;
        return sum;
    }
};
