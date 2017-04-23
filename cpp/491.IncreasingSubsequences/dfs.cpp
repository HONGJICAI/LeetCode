class Solution {
	set<vector<int>>myset;
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		dfs(nums, vector<int>(), 0);
		vector<vector<int>>res(myset.begin(), myset.end());
		return res;
	}
	void dfs(vector<int>&nums, vector<int>arr, int i) {
		if (i == nums.size())return;
		dfs(nums, arr, i + 1);
		if (arr.size()==0||nums[i] >= arr.back()) {
			arr.push_back(nums[i]);
			if (arr.size() > 1 && myset.find(arr)==myset.end()) 
				    myset.insert(arr);
			dfs(nums, arr, i + 1);
		}
	}
};
