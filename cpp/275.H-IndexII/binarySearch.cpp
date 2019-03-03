class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0,r=citations.size()-1,n=citations.size(),res=0;
        while(l<=r){
            int mid=(l+r)/2;
            int num=n-mid,h=citations[mid];
            if(num>h){
                res=max(h,res);
                l=mid+1;
            }
            else{
                res=max(num,res);
                r=mid-1;
            }
        }
        return res;
    }
};
