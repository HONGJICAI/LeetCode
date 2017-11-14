class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int count=0;
        for(auto it=S.rbegin();it!=S.rend();++it)
            if(*it!='-'){
                if(count++==K){
                    count=1;
                    res+='-';
                }
                res+=toupper(*it);
            }
        return string(res.rbegin(),res.rend());
    }
};
