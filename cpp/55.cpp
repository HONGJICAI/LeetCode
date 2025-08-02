// onepass.cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i <= maxReach && i < nums.size(); ++i) {
            maxReach = max(maxReach, i + nums[i]);
        }
        return maxReach >= nums.size() - 1;
    }
};
