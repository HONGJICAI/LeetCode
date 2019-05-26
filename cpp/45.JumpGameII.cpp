class Solution { //Runtime: 12 ms, faster than 93.59% of C++ online submissions for Jump Game II.
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>>qe;
        vector<bool>visited(nums.size(),0);
        if(nums.size()==0)
            return 0;
        qe.push({0,0});
        visited[0] = true;
        while(!qe.empty()){
            const auto [pos,depth]=qe.front();
            if(pos >= nums.size()-1)
                return depth;
            qe.pop();
            for(int i=nums[pos];i>=1;--i)
                if(i+pos>=nums.size()-1)
                    return depth+1;
                else if(visited[i+pos]==0){  
                    visited[i+pos] = 1;
                    qe.push({i+pos,depth+1});
                }
        }
        return 0;
    }
};