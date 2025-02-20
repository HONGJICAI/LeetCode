class Solution { // 16ms
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, result = 0;
        while (i < j) {
            result = max(result, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        }
        return result;
    }
};