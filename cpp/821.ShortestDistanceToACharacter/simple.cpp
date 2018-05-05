class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>res(S.size(),0);
        int l=S.find_first_of(C),r=S.find_last_of(C);
        for(int pos=l;pos>=0;--pos)
            res[pos]=l-pos;
        for(int pos=r;pos<S.size();++pos)
            res[pos]=pos-r;
        while(l!=r){
            int mid=S.find_first_of(C,l+1);
            for(int i=l,j=mid,k=0;i<=j;)
                res[i++]=res[j--]=k++;
            l=mid;
        }
        return res;
    }
};
