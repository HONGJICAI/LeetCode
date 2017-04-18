class Solution {
public:
    string toHex(int num) {
        if(num==0)
            return "0";
        const char hex[17]={"0123456789abcdef"};
        unsigned int number=num;
        string str="";
        while(number>0){
            str=hex[number&0xf]+str;
            number>>=4;
        }
        return str;
    }
};
