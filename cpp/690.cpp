// dfs.cpp
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
  int getImportance(vector<Employee *> employees, int id) {
    Employee *e = employees[id - 1];
    int res = e->importance;
    for (int i = 0; i < e->subordinates.size(); ++i)
      res += getImportance(employees, e->subordinates[i]);
    return res;
  }
};
