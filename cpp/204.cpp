// SieveofEratosthenes-52ms.cpp
class Solution {
public:
  int countPrimes(int n) {
    vector<int> arr(n, 1);
    isPrime(arr);
    int result = 0;
    for (int i = 2; i < n; ++i)
      if (arr[i] == 1)
        ++result;
    return result;
  }
  void isPrime(vector<int> &arr) {
    for (int i = 2; i < arr.size(); ++i)
      if (arr[i] != 0) {
        for (int j = (i << 1); j < arr.size(); j += i)
          arr[j] = 0;
      }
  }
};
