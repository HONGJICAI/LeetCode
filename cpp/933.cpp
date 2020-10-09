class RecentCounter { // 188ms 95.89%
  vector<int> buf;
  int lastCallIdx = 0;
  int binarySearch(int target) {
    int l = lastCallIdx, r = buf.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (buf[m] >= target)
        r = m;
      else
        l = m + 1;
    }
    return r;
  }

public:
  RecentCounter() {}

  int ping(int t) {
    buf.push_back(t);
    lastCallIdx = binarySearch(t - 3000);
    return buf.size() - lastCallIdx;
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

class RecentCounter { // 204ms with stl
  vector<int> buf;
  int lastCallIdx = 0;

public:
  RecentCounter() {}

  int ping(int t) {
    buf.push_back(t);
    lastCallIdx = lower_bound(buf.begin() + lastCallIdx, buf.end(), t - 3000) -
                  buf.begin();
    return buf.size() - lastCallIdx;
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */