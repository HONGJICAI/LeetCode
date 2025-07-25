class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map;
        for (auto ans: answers) {
            ++map[ans + 1];
        }
        int ret = 0;
        for (auto& [k, v]: map) {
            ret += v > k ? (v / k + (v % k != 0)) * k : k;
        }
        return ret;
    }
};