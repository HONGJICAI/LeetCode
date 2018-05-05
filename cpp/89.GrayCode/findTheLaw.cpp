class Solution {
public:
    vector<int> grayCode(int n) {
        if(n<0)
            return vector<int>();
        vector<int>arr{0};
        for(int i=0;i<n;++i){
            int size=arr.size();
            while(--size>=0){
                arr.push_back((1<<i)|arr[size]);
            }
        }
        return arr;
    }
};
