import glob
import os

cpps = glob.glob("cpp/**/*.cpp")
for cpp in cpps:
    print(cpp)
    code = '''
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
'''
    with open(cpp) as f:
        code += f.read()
    with open("a.cpp", "w") as f:
        f.writelines(code)
    cmd = "g++ a.cpp -o a.so -shared -fpic -std=c++17"
    if 0 != os.system(cmd):
        exit(-1)
