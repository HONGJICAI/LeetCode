class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1)return 0;
        int sum=1,i;
        for(i=2;i*i<num;++i){
            if(num%i==0){
                sum+=i;
                sum+=num/i;
            }
        }
        if(i*i==num)
            sum+=i;
        return sum==num;
    }
};
