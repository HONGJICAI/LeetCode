class Solution {
    vector<int>arr;
public:
    Solution(vector<int> nums) {
        arr=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(arr);
        int n=result.size();
        for (int i = 0;i < n;i++) {
            int pos = rand()%n;
            swap(result[pos], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
