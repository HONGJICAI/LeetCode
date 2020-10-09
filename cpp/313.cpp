// better_priority_queue.cpp
class Solution {
  struct ugly {
    int base;
    int index;
    int sum;
    bool operator()(ugly &a, ugly &b) { return a.sum > b.sum; }
  };

public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    priority_queue<ugly, vector<ugly>, ugly> pq;
    vector<int> res(n, 1);
    for (int i = 0; i < primes.size(); ++i)
      pq.push(ugly{primes[i], 0, primes[i]});
    for (int i = 1; i < n; ++i) {
      ugly u = pq.top();
      pq.pop();
      if (u.sum <= res[i - 1])
        --i;
      else
        res[i] = u.sum;
      pq.push(ugly{u.base, ++u.index, u.base * res[u.index]});
    }
    return res[n - 1];
  }
};
// priority_queue.cpp
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    priority_queue<long long int, vector<long long int>, greater<int>> pq;
    pq.push(1);
    long long int last = -1, temp;
    while (n) {
      long long int cur = pq.top();
      pq.pop();
      if (last != cur) {
        last = cur;
        --n;
        for (int num : primes)
          if ((temp = num * cur) <= (long long int)0x7fffffff)
            pq.push(temp);
      }
    }
    return last;
  }
};
// usingVector.cpp
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    vector<int> index(primes.size(), 0), cache(primes), res(n, 1);
    for (int i = 1; i < n; ++i) {
      int minVal = 0x7fffffff, offset;
      for (int j = 0; j < primes.size(); ++j)
        if (cache[j] < minVal) {
          minVal = cache[j];
          offset = j;
        }
      if (minVal <= res[i - 1])
        --i;
      else
        res[i] = minVal;
      cache[offset] = res[index[offset]++] * primes[offset];
    }
    return res[n - 1];
  }
};
