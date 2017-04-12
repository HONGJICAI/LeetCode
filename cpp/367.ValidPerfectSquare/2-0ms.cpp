class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=1,j=num;
        while(i<=j){
            long long mid=(i+j)>>1;
            if(mid*mid==num)
                return 1;
            else if(mid*mid>num)
                j=mid-1;
            else
                i=mid+1;
        }
        return 0;
    }
};
