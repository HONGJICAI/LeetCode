class Solution {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < heights.size();) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                res = max(res, width * h);
            }
        }
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int width =
                st.empty() ? heights.size() : heights.size() - st.top() - 1;
            res = max(res, width * h);
        }
        return res;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret = 0;
        vector<int> heights(matrix[0].size(), 0);
        for (int row = 0; row < matrix.size(); ++row) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                if (matrix[row][col] == '1') {
                    heights[col] = heights[col] > 0 ? heights[col] + 1 : 1;
                } else {
                    heights[col] = 0;
                }
            }
            ret = max(ret, largestRectangleArea(heights));
        }
        return ret;
    }
};