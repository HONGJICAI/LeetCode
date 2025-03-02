// bucket.cpp
class Bucket {
public:
  bool used = false;
  int minval = numeric_limits<int>::max(); // same as INT_MAX
  int maxval = numeric_limits<int>::min(); // same as INT_MIN
};

int maximumGap(vector<int> &nums) {
  if (nums.empty() || nums.size() < 2)
    return 0;

  int mini = *min_element(nums.begin(), nums.end()),
      maxi = *max_element(nums.begin(), nums.end());

  int bucketSize =
      max(1, (maxi - mini) / ((int)nums.size() - 1)); // bucket size or capacity
  int bucketNum = (maxi - mini) / bucketSize + 1;     // number of buckets
  vector<Bucket> buckets(bucketNum);

  for (auto &&num : nums) {
    int bucketIdx = (num - mini) / bucketSize; // locating correct bucket
    buckets[bucketIdx].used = true;
    buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
    buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
  }

  int prevBucketMax = mini, maxGap = 0;
  for (auto &&bucket : buckets) {
    if (!bucket.used)
      continue;

    maxGap = max(maxGap, bucket.minval - prevBucketMax);
    prevBucketMax = bucket.maxval;
  }

  return maxGap;
}
// sort.cpp
int trick = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
class Solution {
public:
  int maximumGap(vector<int> &nums) {
    sort(begin(nums), end(nums));
    int res = 0;
    for (int i = 1; i < nums.size(); ++i)
      res = max(nums[i] - nums[i - 1], res);
    return res;
  }
};
