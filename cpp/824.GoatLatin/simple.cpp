class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string str,res;
        int i =1;
        while(!ss.eof()){
            ss>>str;
            switch(tolower(str[0])){
                case 'a':case 'e':case 'i':case 'o':case 'u':{
                    str+="ma";
                    break;
                }
                default:str=string(str.begin()+1,str.end())+str[0]+"ma";
            }
            str.append(i++,'a');
            res+=res==""?str:" "+str;
        }
        return res;
    }
};
