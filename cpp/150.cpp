// stack-20ms.cpp
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> nums;
    for (auto &s : tokens) {
      if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9')
        nums.push(stoi(s));
      else {
        auto n2 = nums.top();
        nums.pop();
        auto n1 = nums.top();
        nums.pop();
        switch (s[0]) {
        case '+':
          nums.push(n1 + n2);
          break;
        case '-':
          nums.push(n1 - n2);
          break;
        case '*':
          nums.push(n1 * n2);
          break;
        case '/':
          nums.push(n1 / n2);
          break;
        }
      }
    }
    return nums.top();
  }
};
