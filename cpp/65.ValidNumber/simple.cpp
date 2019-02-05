class Solution {
public:
    bool isNumber(string s) {
        s.erase(0,s.find_first_not_of(" "));  
        s.erase(s.find_last_not_of(" ") + 1);
        bool eFlag=false,dotFlag=false,signFlag=false,digitFlag=false;
        for(auto c:s){
            if(c>='0'&&c<='9'){
                digitFlag=true;
            }
            else
                switch(c){
                    case '+':
                    case '-':
                        if(signFlag||digitFlag||dotFlag)
                            return false;
                        signFlag=true;
                        break;
                    case 'e':
                        if(eFlag||!digitFlag)
                            return false;
                        eFlag=true;
                        signFlag=digitFlag=dotFlag=false;
                        break;
                    case '.':
                        if(dotFlag||eFlag)
                            return false;
                        dotFlag=true;
                        break;
                    default:
                        return false;
                }
        }
        return digitFlag;
    }
};
