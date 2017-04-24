class Solution {
    bool can=0;
    int average;
    int a=0,b=0,c=0,d=0;
public:
    bool makesquare(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4||nums.size()==0)return 0;
        sort(nums.begin(),nums.end(),greater<int>());
        average=sum/4;
        if(nums[0]>average)return 0;
        dfs(nums,0);
        return can;
    }
    void dfs(vector<int>&nums,int i){
        if(d==average&a==b&&b==c&&c==d){
            can=1;
            return;
        }
        if(i==nums.size()||a>average||b>average||c>average||d>average||can)
            return;
        a+=nums[i];
        dfs(nums,i+1);
        a-=nums[i];
        b+=nums[i];
        dfs(nums,i+1);
        b-=nums[i];
        c+=nums[i];
        dfs(nums,i+1);
        c-=nums[i];
        d+=nums[i];
        dfs(nums,i+1);
        d-=nums[i];
    }
};
