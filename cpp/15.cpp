class Solution { // sortAndDoublePointer
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int low = i + 1, high = n - 1; low < high;) {
                if (int sum = nums[low] + nums[high]; sum == -nums[i]) {
                    result.push_back({nums[i], nums[low], nums[high]});
                    do {
                        ++low;
                    } while (low < high && nums[low - 1] == nums[low]);
                    do {
                        --high;
                    } while (low < high && nums[high + 1] == nums[high]);
                } else if (sum > -nums[i])
                    --high;
                else
                    ++low;
            }
        }
        return result;
    }
};
class Solution2 { // same logic, but use lambda
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        auto find = [&res](vector<int>& nums, int k) {
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (++i < j && nums[i - 1] == nums[i])
                        ;
                    while (--j > i && nums[j + 1] == nums[j])
                        ;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    --j;
                } else {
                    ++i;
                }
            }
        };
        for (int k = 0; k < nums.size();) {
            find(nums, k);
            while (++k < nums.size() && nums[k - 1] == nums[k])
                ;
        }
        return res;
    }
};