class Solution {
public:
    int compress(vector<char>& chars) {
        int res=0;
        int count=1;
        char last=chars[0];
        for(int i=1;i<chars.size();++i){
            if(chars[i]==last)
                ++count;
            else{
                chars[res++]=last;
                if(count>1){
                    string num=to_string(count);
                    memcpy(&chars[res],&num[0],num.size());
                    res+=num.size();
                }
                last=chars[i];
                count=1;
            }
        }
        chars[res++]=last;
        if(count>1){
            string num=to_string(count);
            memcpy(&chars[res],&num[0],num.size());
            res+=num.size();
        }
        return res;
    }
};
