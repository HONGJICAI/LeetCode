class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string str;
        int num=0;
        while(!ss.eof()){
            getline(ss,str,',');
            num+=str=="#"?-1:1;
            if(num==-1)
                break;
        }
        return num==-1&&ss.eof();
    }
};
