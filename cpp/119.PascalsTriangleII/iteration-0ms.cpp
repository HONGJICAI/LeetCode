class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>a(rowIndex+1,1);
        for(int row=2;row<=rowIndex;++row)
            for(int i=row-1;i>0;--i)
                a[i]=a[i]+a[i-1];
        return a;
    }
};