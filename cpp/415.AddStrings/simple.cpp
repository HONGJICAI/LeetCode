class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size()-1,n2=num2.size()-1,c=0;
        string res="";
        while(n1>=0||n2>=0||c>0){
            if(n1>=0)c+=num1[n1--]-'0';
            if(n2>=0)c+=num2[n2--]-'0';
            res=char(c%10+'0')+res;
            c/=10;
        }
        return res;
    }
};
