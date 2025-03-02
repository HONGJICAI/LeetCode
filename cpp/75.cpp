class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int cur = i;
        while (cur <= j) {
            while (cur <= j && nums[cur] == 0)
                swap(nums[cur++], nums[i++]);
            while (cur <= j && nums[cur] == 1)
                ++cur;
            while (cur <= j && nums[cur] == 2)
                swap(nums[cur], nums[j--]);
        }
    }
};
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        for (int i = 0, l = 0, r = nums.size() - 1; i <= r;) {
            switch (nums[i]) {
            case 0:
                swap(nums[i], nums[l++]);
            case 1:
                i++;
                break;
            case 2:
                swap(nums[i], nums[r--]);
                break;
            }
        }
    }
};