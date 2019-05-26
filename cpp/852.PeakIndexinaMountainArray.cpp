class Solution { //16ms
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l=0,r=A.size()-1;
        while(r-l>3){
            int ll=l+(r-l)/3;
            int rr=l+(r-l)/3*2;
            if(A[ll]>=A[rr])
                r=rr;
            if(A[ll]<=A[rr])
                l=ll;
        }
        return max_element(A.begin()+l,A.begin()+r)-A.begin();
    }
};