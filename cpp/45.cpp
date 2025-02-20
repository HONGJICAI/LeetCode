class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int l = 0, r = 1, step = 0, most = 0;
        while (l < r) {
            ++step;
            while (l < r) {
                most = max(l + nums[l], most);
                ++l;
            }
            if (most >= nums.size() - 1)
                return step;
            r = most + 1;
        }
        return step;
    }
};
class SolutionBFS {
public:
    int jump(vector<int>& nums) {
        queue<pair<int, int>> qe;
        vector<bool> visited(nums.size(), 0);
        if (nums.size() <= 1)
            return 0;
        qe.push({0, 0});
        visited[0] = true;
        while (!qe.empty()) {
            const auto [pos, depth] = qe.front();
            qe.pop();
            for (int i = nums[pos]; i >= 1; --i)
                if (i + pos >= nums.size() - 1)
                    return depth + 1;
                else if (visited[i + pos] == 0) {
                    visited[i + pos] = 1;
                    qe.push({i + pos, depth + 1});
                }
        }
        return 0;
    }
};
class SolutionIterative {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size(), INT_MAX / 2);
        res[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int step = nums[i]; step > 0; --step) {
                if (i + step < nums.size()) {
                    res[i + step] = min(res[i + step], res[i] + 1);
                }
            }
        }
        return res.back();
    }
};