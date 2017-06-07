class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int kinds=unordered_set<int>(candies.begin(),candies.end()).size(),n=candies.size()/2;
        return kinds>=n?n:kinds;
    }
};
