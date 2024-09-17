// dp-0ms.cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        auto previous = make_pair(1, 2);
        for (int i = 3; i <= n; ++i) {
            previous = {previous.second, previous.first + previous.second};
        }
        return previous.second;
    }
};