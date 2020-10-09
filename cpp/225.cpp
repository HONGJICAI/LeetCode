// notBest-3ms.cpp
class MyStack {
  queue<int> qe;

public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    int size = qe.size(), i = 0;
    qe.push(x);
    while (i < size) {
      qe.push(qe.front());
      qe.pop();
      ++i;
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int temp = qe.front();
    qe.pop();
    return temp;
  }

  /** Get the top element. */
  int top() { return qe.front(); }

  /** Returns whether the stack is empty. */
  bool empty() { return qe.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
