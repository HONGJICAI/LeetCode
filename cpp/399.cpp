class Solution {
  // speed can be improved but it reach 0ms now
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Evaluate
  // Division. Memory Usage: 9.3 MB, less than 81.50% of C++ online submissions
  // for Evaluate Division.
public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    using pp = pair<bool, double>;
    using sv = string_view;
    unordered_map<sv, vector<pair<sv, double>>> children;
    for (int i = 0; i < equations.size(); i++) {
      children[equations[i][0]].push_back({equations[i][1], values[i]});
      children[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
    }
    unordered_set<sv> visited;
    function<pp(sv, sv, double)> dfs =
        [&dfs, &visited, &children](sv a, sv b, double val) -> pp {
      if (!visited.count(a)) {
        visited.insert(a);
        for (auto &p : children[a])
          if (p.first == b)
            return {true, val * p.second};
          else if (auto result = dfs(p.first, b, val * p.second); result.first)
            return result;
      }
      return {false, -1.0};
    };
    vector<double> ans;
    for (auto &p : queries) {
      ans.push_back(p[0] == p[1] && children.count(p[0])
                        ? 1.0
                        : dfs(p[0], p[1], 1.0).second);
      visited.clear();
    }
    return ans;
  }
};