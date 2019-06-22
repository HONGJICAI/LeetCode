class Solution {
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
//Memory Usage: 8.1 MB, less than 84.49% of C++ online submissions for Sqrt(x).
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int low=1,high=x;
        while(low<high){
            int mid=low+(high-low)/2;
            int result=x/mid;
            if(result==mid)
                return mid;
            else if(result<mid)
                high=mid-1;
            else
                low=mid+1;
        }
        return (long long)low*low>x?low-1:low;
    }
};