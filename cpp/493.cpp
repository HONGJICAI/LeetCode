class Solution {
    int result = 0;
    void divide(auto& nums, int left, int right) {
        if (left + 1 >= right) return;
        auto mid = left + (right - left) / 2;;
        divide(nums, left, mid);
        divide(nums, mid, right);
        calc(nums.begin() + left, nums.begin() + mid, nums.begin() + mid, nums.begin() + right);
        merge(nums.begin() + left, nums.begin() + mid, nums.begin() + mid, nums.begin() + right);
    }
    auto calc(auto it1, auto it1e, auto it2, auto it2e) {
        while(it1 != it1e && it2 != it2e) {
            if (*it1 <= 2l* *it2) {
                it1++;
            } else {
                result += it1e - it1;
                it2++;
            }
        }
    }
    auto merge(auto it1, auto it1e, auto it2, auto it2e) {
        vector<int> ret;
        ret.reserve(it2e - it1);
        auto originBegin = it1;
        while(it1 != it1e && it2 != it2e) {
            if (*it1 <= *it2) {
                ret.push_back(*it1++);
            } else {
                ret.push_back(*it2++);
            }
        }
        while (it1 != it1e) {
            ret.push_back(*it1++);
        }
        while (it2 != it2e) {            
            ret.push_back(*it2++);
        }
        for (auto num: ret)
            *originBegin++ = num;
    }
public:
    int reversePairs(vector<int>& nums) {
        divide(nums, 0, nums.size());
        return result;
    }
};