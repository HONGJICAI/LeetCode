class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==n)
            return n;
        int count=0;
        for(int v=n;v>0;++count)
            v>>=1;
        int res=0;
        do{
            int a=(1<<(count-1))&m;
            int b=(1<<(count-1))&n;
            if(a==b)
                res|=a;
            else
                break;
        }while(--count);
        return res;
    }
};
