class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret(nums.size(), 0);
        vector<pair<int, int>> indexedNums(nums.size());
        for (auto i = 0; i < nums.size(); ++i)
            indexedNums[i] = {nums[i], i};
        auto merge = [&ret](auto left, auto right) {
            vector<pair<int, int>> result(left.size() + right.size());
            auto it = result.begin();
            for (auto l = left.begin(), r = right.begin(); l != left.end() || r != right.end(); ++it) {
                if (l == left.end()) {
                    *it = *r++;
                } else if (r == right.end()) {
                    ret[l->second] += r - right.begin();
                    *it = *l++;
                } else if (l->first <= r->first) {
                    ret[l->second] += r - right.begin();
                    *it = *l++;
                } else if (l->first > r->first) {
                    *it = *r++;
                }
            }
            it = result.begin();
            for (auto& val: left)
                val = *it++;
            for (auto& val: right)
                val = *it++;
        };
        function<void(span<pair<int, int>>)> mergeSort = [&](auto nums) {
            if (nums.size() <= 1)
                return;
            int mid = nums.size() / 2;
            auto left = nums.subspan(0, mid);
            auto right = nums.subspan(mid);
            mergeSort(left);
            mergeSort(right);
            merge(left, right);
        };
        mergeSort(indexedNums);
        return ret;
    }
};