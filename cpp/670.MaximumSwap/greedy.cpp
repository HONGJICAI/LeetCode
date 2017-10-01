class Solution {
public:
    int maximumSwap(int num) {
        string res=to_string(num);
        int index1=-1,index2;
        for(int i=0;i<res.size();++i){
            for(int j=res.size()-1;j>i;--j){
                if(res[j]>res[i]){
                    if(index1==-1)
                        index1=i,index2=j;
                    else if(res[index2]<res[j])
                        index2=j;
                }
            }
            if(index1!=-1)
                break;
        }
        if(index1==-1)
            return num;
        swap(res[index1],res[index2]);
        return stoi(res);
    }
};
