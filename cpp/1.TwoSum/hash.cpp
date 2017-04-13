class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int>map;
		vector<int>a;
		int len = nums.size();
		for (int i = 0; i<len; i++) {
			int result = target - nums[i];
			if (map.find(result) != map.end()) {
			    a={map[result],i};
				return a;
			}
			map[nums[i]]= i;
		}
	}
};
