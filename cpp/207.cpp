// simple.cpp
class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> reverse(numCourses);
    vector<int> counts(numCourses, 0);
    for (auto p : prerequisites) {
      reverse[p.second].push_back(p.first);
      counts[p.first]++;
    }
    int finished = 0;
    for (auto it = find(counts.begin(), counts.end(), 0); it != counts.end();) {
      ++finished;
      *it = -1;
      int index = (int)(it - counts.begin());
      for (int num : reverse[index])
        counts[num]--;
      it = find(counts.begin(), counts.end(), 0);
    }
    return finished == numCourses;
  }
};
