class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        int m=matrix.size();
        if(m<1)return result;
        int n=matrix[0].size();
        int i=0,j=0;
        while(n>0&&m>0){
            result.push_back(matrix[i][j]);
            int k=1;
            --n;
            while(k<=n){
                result.push_back(matrix[i][j+k]);
                ++k;
            }
            j=j+n;
            k=1;
            --m;
            if(m==0)break;
            while(k<=m){
                result.push_back(matrix[i+k][j]);
                ++k;
            }
            i=i+m;
            k=1;
            if(n==0)break;
            while(k<=n){
                result.push_back(matrix[i][j-k]);
                ++k;
            }
            j=j-n;
            k=1;
            --m;
            while(k<=m){
                result.push_back(matrix[i-k][j]);
                ++k;
            }
            i=i-m;
            j+=1;
            --n;
        }
        return result;
    }
};
