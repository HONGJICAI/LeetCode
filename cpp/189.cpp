// reverse3times-19ms.cpp
class Solution {
    void rotate(span<int> nums) { reverse(nums.begin(), nums.end()); }

  public:
    void rotate(vector<int>& nums, int k) {
        if (!(k %= nums.size()))
            return;
        rotate(nums);
        rotate(span(nums).subspan(0, k));
        rotate(span(nums).subspan(k));
    }
};
