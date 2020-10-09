class Solution {
  // Runtime: 124 ms, faster than 27.62% of C++ online submissions for Task
  // Scheduler. Memory Usage: 19 MB, less than 20.41% of C++ online submissions
  // for Task Scheduler.
public:
  int leastInterval(vector<char> &tasks, int n) {
    int counter[26] = {};
    for (char task : tasks)
      counter[task - 'A']++;
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++)
      if (counter[i])
        pq.push(counter[i]);
    int time = 0;
    while (pq.size()) {
      vector<int> remaining;
      int all = n + 1;
      while (all and pq.size()) {
        int counts = pq.top();
        pq.pop();
        if (--counts)
          remaining.push_back(counts);
        time++;
        all--;
      }
      for (int counts : remaining)
        pq.push(counts);
      if (pq.empty())
        break;
      time += all;
    }
    return time;
  }
};