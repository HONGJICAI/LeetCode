class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size();
        string res(m+n,0);
        for(int i=m-1;i>=0;--i)
            for(int j=n-1;j>=0;--j){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j,p2=i+j+1;
                int sum=mul+res[p2];
                res[p2]=sum%10;
                res[p1]+=sum/10;
            }
        int off;
        for(off=0;off<res.size()&&res[off]==0;++off);
        res=res.substr(off);
        for(int i=0;i<res.size();++i)
            res[i]+='0';
        return res.size()==0?"0":res;    
    }
};
