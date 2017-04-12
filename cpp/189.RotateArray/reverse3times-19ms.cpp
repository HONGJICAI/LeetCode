class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if( ! (k%=len) )return;
        int off=len-k,i,j;
        for(i=0,j=off-1;i<j;++i,--j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
         
        for(i=off,j=len-1;i<j;++i,--j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }   
        
        for(i=0,j=len-1;i<j;++i,--j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
};
