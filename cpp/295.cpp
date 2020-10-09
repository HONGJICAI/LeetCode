// usingTwoPriority_queue.cpp
class MedianFinder {
  int count, mid;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  priority_queue<int, vector<int>, less<int>> maxHeap;

public:
  /** initialize your data structure here. */
  MedianFinder() {
    count = 0;
    minHeap.push(0x7fffffff);
    maxHeap.push(0x80000000);
  }

  void addNum(int num) {
    ++count;
    if (count & 1)
      mid = num;
    else {
      minHeap.push(max(mid, num));
      maxHeap.push(min(mid, num));
    }
  }

  double findMedian() {
    while (minHeap.top() < maxHeap.top()) {
      minHeap.push(maxHeap.top());
      maxHeap.push(minHeap.top());
      minHeap.pop();
      maxHeap.pop();
    }
    if ((count & 1) == 0)
      return (double)(minHeap.top() + maxHeap.top()) / 2;
    if (mid >= minHeap.top()) {
      minHeap.push(mid);
      mid = minHeap.top();
      minHeap.pop();
    } else if (mid <= maxHeap.top()) {
      maxHeap.push(mid);
      mid = maxHeap.top();
      maxHeap.pop();
    }
    return mid;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
