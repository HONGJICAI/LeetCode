class Solution {
  // Runtime: 240 ms, faster than 80.16% of C++ online submissions for K Closest
  // Points to Origin. Memory Usage: 36.9 MB, less than 92.75% of C++ online
  // submissions for K Closest Points to Origin.
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    struct compare {
      bool operator()(vector<int> &p, vector<int> &q) {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
      }
    } cmp;
    vector<vector<int>> heap(points.begin(), points.begin() + K);
    make_heap(heap.begin(), heap.end(), cmp);
    for (int i = K; i < points.size(); ++i)
      if (cmp(points[i], heap[0])) {
        pop_heap(heap.begin(), heap.end(), cmp);
        heap.pop_back();
        heap.push_back(move(points[i]));
        push_heap(heap.begin(), heap.end(), cmp);
      }
    return heap;
  }
};