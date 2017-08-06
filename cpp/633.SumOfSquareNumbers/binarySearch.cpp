class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long int i=0;i*i<=c;++i){
            long long int res=c-i*i;
            if(helper(0,res,res))
                return true;
        }
        return false;
    }
    bool helper(int left,int right,int num){
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if(mid*mid==num)
                return true;
            else if(mid*mid<num)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};
