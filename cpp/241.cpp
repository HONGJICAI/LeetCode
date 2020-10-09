class Solution {
  // Runtime: 0 ms Your runtime beats 100.00 % of cpp submissions
  // Memory Usage: 9.1 MB Your memory usage beats 95.63 % of cpp submissions.
public:
  vector<int> diffWaysToCompute(string input) {
    unordered_map<string_view, vector<int>> dpMap;
    function<void(string_view)> recursion = [&](string_view input) {
      vector<int> result;
      for (int i = 0; i < input.size(); i++) {
        char cur = input[i];
        if (cur == '+' || cur == '-' || cur == '*') {
          auto substr = input.substr(0, i);
          if (dpMap.find(substr) == dpMap.end())
            recursion(substr);
          auto &result1 = dpMap[substr];
          substr = input.substr(i + 1);
          if (dpMap.find(substr) == dpMap.end())
            recursion(substr);
          auto &result2 = dpMap[substr];
          for (auto n1 : result1)
            for (auto n2 : result2)
              switch (cur) {
              case '+':
                result.push_back(n1 + n2);
                break;
              case '-':
                result.push_back(n1 - n2);
                break;
              case '*':
                result.push_back(n1 * n2);
                break;
              }
        }
      }
      if (result.empty()) {
        int res;
        from_chars(input.data(), input.data() + input.size(), res);
        result.push_back(res);
      }
      dpMap[input] = move(result);
    };
    recursion(input);
    return dpMap[input];
  }
};