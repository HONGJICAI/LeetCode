class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0,j=1;
        vector<int> res(A.size());
        for(auto num:A){
            auto& index = num&1 ?j:i;
            res[index]=num;
            index+=2;
        }
        return res;
    }
};
