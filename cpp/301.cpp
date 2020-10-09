class Solution {
  // Runtime: 124 ms, faster than 15.73% of C++ online submissions for Remove
  // Invalid Parentheses. Memory Usage: 10.9 MB, less than 64.65% of C++ online
  // submissions for Remove Invalid Parentheses.
public:
  vector<string> removeInvalidParentheses(string_view s) {
    unordered_set<string> ret;
    using itr = string_view::iterator;
    function<void(itr, itr, int, string &)> dfs =
        [&ret, &dfs](auto first, auto last, auto remain, auto &now) {
          if (ret.size() and last - first + now.size() < begin(ret)->size())
            return;
          if (first == last) {
            if (remain)
              return;
            if (not ret.size() or begin(ret)->size() == now.size())
              ret.insert(now);
            if (begin(ret)->size() < now.size())
              ret = {now};
            return;
          }
          int remainIfPush;
          switch (*first) {
          case '(':
            remainIfPush = remain + 1;
            break;
          case ')':
            remainIfPush = remain - 1;
            break;
          default:
            remainIfPush = remain;
          }
          if (remainIfPush >= 0) {
            now.push_back(*first);
            dfs(first + 1, last, remainIfPush, now);
            now.pop_back();
          }
          dfs(first + 1, last, remain, now);
        };
    string now;
    dfs(begin(s), end(s), 0, now);
    return {begin(ret), end(ret)};
  }
};