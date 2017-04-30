class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>>qe;
        vector<bool>visited(nums.size(),0);
        if(nums.size()==0)return 0;
        qe.push(pair<int,int>(0,0));
        visited[0] = true;
        while(!qe.empty()){
            int fro=qe.front().first;
            int depth = qe.front().second;
            if(fro >= nums.size()-1)
                return depth;
            qe.pop();
            for(int i=nums[fro];i>=1;--i)
                if(i+fro>=nums.size()-1)
                    return depth+1;
                else if(visited[i+fro]==0){  
                    visited[i+fro] = 1;
                    qe.push(pair<int,int>(i+fro,depth+1));
                }
        }
        return 0;
    }
};
