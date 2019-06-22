class Solution {
//Runtime: 16 ms, faster than 44.02% of C++ online submissions for Partition to K Equal Sum Subsets.
//Memory Usage: 8.3 MB, less than 61.79% of C++ online submissions for Partition to K Equal Sum Subsets.
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums),end(nums),0);
        if(k <= 0 or sum%k != 0) return false;
        vector<int> visited(nums.size(), 0);
        int target = sum/k;
        function<bool(int,int,int)>canPartition=[&](int start_index, int k, int cur_sum){
            if(k==1)
                return true;
            if(cur_sum == target)
                return canPartition(0, k-1, 0);
            for(int i = start_index; i<nums.size(); i++)
                if(!visited[i]){
                    visited[i] = 1;
                    if(canPartition(i+1, k, cur_sum + nums[i]))
                        return true;
                    visited[i] = 0;
                }
            return false;
        };
        return canPartition(0, k, 0);
    }
};
class Solution {
//Runtime: 0 ms
//Memory Usage: 8.2 MB
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums),end(nums),0);
        sort(nums.begin(), nums.end(), greater<int>());
        if (sum%k != 0) return false;
        int target = sum/k;        
        vector<int> buckets(k, 0);
        function<bool(int)> dfs=[&](int idx) {
            if (idx == nums.size()) {
                for (auto num:buckets)
                    if (num != target) return false;
                return true;
            }
            for(auto &val:buckets) {
                int curr = nums[idx];
                if (curr + val > target) continue;
                val += curr;
                if(dfs(idx+1))
                    return true;
                val -= curr;
                if (val == 0) break;
            }
            return false;
        };
        return dfs(0);
    }
};