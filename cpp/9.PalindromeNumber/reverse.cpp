class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return 0;
        int reverseX=0,copy=x;
        while(x>0){
            reverseX*=10;
            reverseX+=x%10;
            x/=10;
        }
        return reverseX==copy;
    }
};
