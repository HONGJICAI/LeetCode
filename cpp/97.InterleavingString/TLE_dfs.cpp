class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return 0;
        return dfs(s1,s2,s3,0,0,0);
    }
    bool dfs(string& s1,string& s2,string& s3,int i,int j,int k){
        if(i==s1.size()&&j==s2.size())
            return true;
        bool res=0;
        if(i<s1.size()&&s1[i]==s3[k])
            res|=dfs(s1,s2,s3,i+1,j,k+1);
        if(j<s2.size()&&s2[j]==s3[k])
            res|=dfs(s1,s2,s3,i,j+1,k+1);
        return res;
    }
};
