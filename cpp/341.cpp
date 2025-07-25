/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    using Node = pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>;
    stack<Node> st;
    void expand() {    
        while (st.size()) {
            auto [cur, end] = st.top();
            if (cur->isInteger()) break;
            auto& nested = cur->getList();
            st.pop();
            if (cur + 1 != end)
                st.push({cur + 1, end});
            if (nested.size())
                st.push({nested.begin(), nested.end()});
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (nestedList.size() == 0) return;
        st.push({nestedList.begin(), nestedList.end()});
    }
    
    int next() {
        auto [cur, end] = st.top();
        st.pop();
        if (cur + 1 != end) {
            st.push({cur + 1, end});
        }
        return cur->getInteger();
    }
    
    bool hasNext() {
        expand();
        return st.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */