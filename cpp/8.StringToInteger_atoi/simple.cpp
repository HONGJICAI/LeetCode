class Solution {
public:
    int myAtoi(string str) {
        int len=str.size();
        if(len==0)return 0;
        int i,j;
        for(j=0;j<len&&str[j]==' ';++j);
        int sign=1;
        if(str[j]=='-'||str[j]=='+'){
            sign=str[j]=='-'?-1:1;
            ++j;
        }
        if(!(str[j]>='0'&&str[j]<='9'))return 0;
        for(i=j;i<len;++i)
            if(!(str[i]>='0'&&str[i]<='9'))break;
        int result=0;
        while(j<i){
            result=result*10+str[j++]-'0';
            if( (result>INT_MAX/10&&j<i)||(result==INT_MAX/10&&j<i&&str[j]>'7'))
                return sign==1?INT_MAX:INT_MIN;
        }
        return sign*result;
    }
    
};
