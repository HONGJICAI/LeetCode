class Solution {
    bool valid(int number){
        bool valid = false;
        while(number){
            switch(number%10){
                case 2:
                case 5:
                case 6:
                case 9:valid = true;break;
                case 3:
                case 4:
                case 7:return false;
            }
            number/=10;
        }
        return valid;
    }
public:
    int rotatedDigits(int N) {
        int count = 0;
        for(int i=1;i<=N;++i)
            if(valid(i))
                ++count;
        return count;
    }
};
