class SolutionMLE {
    vector<int> monotonicStack(vector<int>& nums, int k) {
        if (k == 0) return {};
        vector<int> ret;
        int drop = nums.size() - k;
        for (auto num: nums) {
            while (ret.size() && drop && ret.back() < num) {
                ret.pop_back();
                --drop;
            }
            ret.push_back(num);
        }
        ret.erase(ret.begin() + k, ret.end());
        return ret;
    }
    auto compare(auto it1b, auto it1e, auto it2b, auto it2e) {
        for (;it1b != it1e && it2b != it2e; ++it1b, ++it2b) {
            if (*it1b > *it2b)
                return true;
            else if (*it1b < *it2b)
                return false;
        }
        return true;
    }
    vector<int> merge(const span<int>& left, const span<int>& right) {
        vector<int> ret;
        auto it1 = left.begin(), it2 = right.begin();
        while (it1 != left.end() && it2 != right.end()) {
            if (*it1 == *it2) {
                auto take1 = merge(span(it1 + 1, left.end()), span(it2, right.end()));
                auto take2 = merge(span(it1, left.end()), span(it2 + 1, right.end()));
                auto& take = compare(take1.begin(), take1.end(), take2.begin(), take2.end()) ? take1 : take2;
                ret.push_back(*it1);
                ret.insert(ret.end(), take.begin(), take.end());
                return ret;
            } else {
                auto& it = *it1 < *it2 ? it2 : it1;
                ret.push_back(*it++);
            }
        }
        while (it1 != left.end())
            ret.push_back(*it1++); 
        while (it2 != right.end())
            ret.push_back(*it2++); 
        return ret;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size()) return maxNumber(nums2, nums1, k);
        vector<int> ret;
        int l = k > nums2.size() ?  k - nums2.size() : 0;
        for (;l <= k && l <= nums1.size(); ++l) {
            auto left = monotonicStack(nums1, l);
            auto right = monotonicStack(nums2, k - l);
            auto result = merge(left, right);
            if (ret.empty()) {
                ret = move(result);
            } else if (!compare(ret.begin(), ret.end(), result.begin(), result.end())) {
                ret = move(result);
            }
        }
        return ret;
    }
};
class Solution {
    vector<int> monotonicStack(vector<int>& nums, int k) {
        if (k == 0) return {};
        vector<int> ret;
        int drop = nums.size() - k;
        for (auto num: nums) {
            while (ret.size() && drop && ret.back() < num) {
                ret.pop_back();
                --drop;
            }
            ret.push_back(num);
        }
        ret.erase(ret.begin() + k, ret.end());
        return ret;
    }
    auto compare(auto it1b, auto it1e, auto it2b, auto it2e, int defaultVal = 0) {
        for (;it1b != it1e && it2b != it2e; ++it1b, ++it2b) {
            if (*it1b > *it2b)
                return true;
            else if (*it1b < *it2b)
                return false;
        }
        for (; it1b != it1e; ++it1b)
            if (*it1b > defaultVal)
                return true;
            else if (*it1b < defaultVal)
                return false;
        for (; it2b != it2e; ++it2b)
            if (*it2b > defaultVal)
                return false;
            else if (*it2b < defaultVal)
                return true;
        return true;
    }
    vector<int> merge(const span<int>& left, const span<int>& right) {
        vector<int> ret;
        auto it1 = left.begin(), it2 = right.begin();
        while (it1 != left.end() && it2 != right.end()) {
            if (*it1 == *it2) {
                if (compare(it1 + 1, left.end(), it2 + 1, right.end(), *it1))
                    ret.push_back(*it1++);
                else
                    ret.push_back(*it2++);
            } else {
                auto& it = *it1 < *it2 ? it2 : it1;
                ret.push_back(*it++);
            }
        }
        while (it1 != left.end())
            ret.push_back(*it1++); 
        while (it2 != right.end())
            ret.push_back(*it2++); 
        return ret;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size()) return maxNumber(nums2, nums1, k);
        vector<int> ret;
        int l = k > nums2.size() ?  k - nums2.size() : 0;
        for (;l <= k && l <= nums1.size(); ++l) {
            auto left = monotonicStack(nums1, l);
            auto right = monotonicStack(nums2, k - l);
            auto result = merge(left, right);
            if (ret.empty()) {
                ret = move(result);
            } else if (!compare(ret.begin(), ret.end(), result.begin(), result.end())) {
                ret = move(result);
            }
        }
        return ret;
    }
};