class Solution {
public:
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
            int width = st.empty() ? heights.size() : heights.size() - st.top() - 1;
            res = max(res, width * h);
        }
        return res;
    }
};