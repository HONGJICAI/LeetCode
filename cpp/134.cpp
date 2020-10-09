// singleScan.cpp
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0, start = 0, end = 0, visited = 0, n = gas.size();
    while (visited < n) {
      for (; visited < n && total >= 0; visited++) {
        total += gas[end] - cost[end];
        end = (end + 1) % n;
      }
      for (; visited < n && total < 0; visited++) {
        start = start - 1 < 0 ? start - 1 + n : start - 1;
        total += gas[start] - cost[start];
      }
    }
    return total >= 0 ? start : -1;
  }
};
