class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int min = INT_MAX, i = 0, j = 0, n = nums.size(), sum = 0;
		if (n == 0)return 0;
		while(j<n){
		    sum+=nums[j++];
		    while(sum>=s){
				min = min<j - i ? min : j - i;
				sum -= nums[i++];
			}
		}
		return min == INT_MAX ? 0 : min;
	}
};
