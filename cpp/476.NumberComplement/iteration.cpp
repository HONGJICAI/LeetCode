class Solution {
public:
    int findComplement(int num) {
        int count=0,num2=num;
        while(num2){
            count++;
            num2>>=1;
        }
        int i=(1<<count)-1;
        return i-num;
    }
};
