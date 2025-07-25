class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = 1, cur = 1;
        pair<int, int> high = {1, 0}; // val, idx
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) { // go up
                high = {++cur, i};
            } else if (ratings[i] < ratings[i-1]) { // go down
                cur = 1;
                total += i - (high.second + 1); // increase if continuously go down
                if (i - high.second >= high.first) // special check for highest point
                    total += 1;
            } else {
                high = {cur = 1, i};
            }
            total += cur;
        }
        return total;
    }
};