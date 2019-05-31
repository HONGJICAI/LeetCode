class Solution { // Runtime: 4 ms, faster than 97.26% of C++ online submissions for Remove Outermost Parentheses.
public:
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++)
                res += c;
            else if (c == ')' && --opened)
                res += c;
        }
        return res;
    }
};