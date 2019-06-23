class Solution {
//Runtime: 16 ms, faster than 79.20% of C++ online submissions for UTF-8 Validation.
//Memory Usage: 9.5 MB, less than 59.65% of C++ online submissions for UTF-8 Validation.
public:
    bool validUtf8(vector<int>& data) {
        int status=0;
        for(auto val:data){
            auto d=val&0xff;
            if(status){
                if(not((d>>6)==0b10)) return false;
                --status;
            }
            else{
                if((d>>7)==0);
                else if((d>>5)==0b110)
                    status+=1;
                else if((d>>4)==0b1110)
                    status+=2;
                else if((d>>3)==0b11110)
                    status+=3;
                else return false;
            }
        }
        return status==0;
    }
};