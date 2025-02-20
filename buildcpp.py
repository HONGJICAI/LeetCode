import glob
import os

cpps = glob.glob("cpp/*.cpp")
errors = []
for cpp in cpps:
    print(cpp)
    code = '''
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
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
'''
    with open(cpp) as f:
        code += f.read()
    with open("a.cpp", "w") as f:
        f.writelines(code)
    cmd = "g++ a.cpp -o a.so -shared -fpic -std=c++20"
    if 0 != os.system(cmd):
        errors.append(cpp)
if len(errors) > 0:
    print("Errors in the following files:")
    for error in errors:
        print(error)
    exit(1)
print("All files compiled successfully.")
