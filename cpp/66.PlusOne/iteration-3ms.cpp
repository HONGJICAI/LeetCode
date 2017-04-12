class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size(),carry=0;
        for(int i=len-1;i>=0;--i){
            digits[i]+=1;
            if(digits[i]>=10){
                digits[i]-=10;
                carry=1;
            }
            else
                carry=0;
            if(carry==0)
                break;
        }
        if(carry==1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
