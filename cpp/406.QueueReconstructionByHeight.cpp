class Solution {
//Runtime: 76 ms, faster than 42.25% of C++ online submissions for Queue Reconstruction by Height.
//https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89348/6-lines-Concise-C%2B%2B
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const auto& p1, const auto& p2){
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        vector<vector<int>> res;
        for (auto& p : people) 
            res.insert(res.begin() + p[1], p);
        return res;
    }
};
class Solution { // better than first one because of the use of list
//Runtime: 40 ms, faster than 94.96% of C++ online submissions for Queue Reconstruction by Height.
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const auto& p1, const auto& p2){
            return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        list<vector<int>> res;
        for (auto& p : people) 
            res.insert(next(res.begin(),p[1]), p);
        return {make_move_iterator(res.begin()),make_move_iterator(res.end())};
    }
};