class Solution {
  // Runtime: 8 ms, faster than 98.83% of C++ online submissions for Keys and
  // Rooms. Memory Usage: 10.9 MB, less than 70.73% of C++ online submissions
  // for Keys and Rooms.
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    vector<int> st = {0};
    unordered_set<int> seen = {0};
    while (!st.empty()) {
      int i = st.back();
      st.pop_back();
      for (int j : rooms[i])
        if (seen.count(j) == 0) {
          st.push_back(j);
          seen.insert(j);
          if (rooms.size() == seen.size())
            return true;
        }
    }
    return rooms.size() == seen.size();
  }
};