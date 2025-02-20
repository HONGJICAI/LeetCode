// doubleStack-26ms.cpp
class MinStack {
  stack<int> st;
  stack<int> min;

public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (min.size() == 0)
      min.push(x);
    else if (min.top() >= x)
      min.push(x);
    st.push(x);
  }

  void pop() {
    if (st.top() == min.top())
      min.pop();
    st.pop();
  }

  int top() { return st.top(); }

  int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
