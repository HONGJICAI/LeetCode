/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* divide(vector<vector<int>>& grid, const pair<int,int>& topLeft, const pair<int,int>& bottomRight) {
        auto& [top, left] = topLeft;
        auto& [bottom, right] = bottomRight;
        pair<int, int> center = {(top + bottom)/2, (left+right)/2};
        if (top + 1 == bottom)
            return new Node(grid[top][left], true, nullptr, nullptr, nullptr, nullptr);
        auto tl = divide(grid, topLeft, center);
        auto tr = divide(grid, {top, center.second}, {center.first, right});
        auto bl = divide(grid, {center.first, left}, {bottom, center.second});
        auto br = divide(grid, center, bottomRight);
        auto children = {tl, tr, bl, br};
        if (ranges::all_of(children, [](auto& x){ return x->val && x->isLeaf; })) {
            delete tl, tr, bl, br;
            return new Node(1, true, nullptr, nullptr, nullptr, nullptr);
        }
        if (ranges::all_of(children, [](auto& x){ return !x->val && x->isLeaf; })) {
            delete tl, tr, bl, br;
            return new Node(0, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(1, false, tl, tr, bl, br);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return divide(grid, {0, 0}, {grid.size(), grid.size()});
    }
};