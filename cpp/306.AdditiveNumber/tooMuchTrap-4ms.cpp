class Solution {
    bool search(long long val,long long lastVal,string &str,int offset){
        auto s=to_string(val);
        if(str.size()-offset>=s.size()&&str.substr(offset,s.size())==s)
            return offset+s.size()==str.size()?true:search(lastVal+val,val,str,offset+s.size());
        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        for(int i=1;i+i<num.size();++i){ // i is the length of num1
            auto a=stol(num.substr(0,i));
            for(int j=1;i+j+j<=num.size();++j){ // j is the length of num1
                auto b=stol(num.substr(i,j));
                if(search(a+b,b,num,i+j))
                    return true;
                if(num[i]=='0')
                    break;
            }
            if(num[0]=='0')
                break;
        }
        return false;
    }
};// uint64, leading 0,num2 < num1
