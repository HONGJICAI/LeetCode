// stack.cpp
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    int n = heights.size(), maxArea = 0;
    for (int i = 0; i < heights.size();)
      if (st.empty() || heights[st.top()] <= heights[i])
        st.push(i++);
      else {
        int top = st.top();
        st.pop();
        maxArea =
            max(maxArea, heights[top] * (st.empty() ? i : i - st.top() - 1));
      }
    while (!st.empty()) {
      int top = st.top();
      st.pop();
      maxArea =
          max(maxArea, heights[top] * ((st.empty() ? n : n - st.top() - 1)));
    }
    return maxArea;
  }
};
