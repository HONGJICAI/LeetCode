class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for(auto ch:s){
            switch (ch){
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                case '}':
                case ']':
                    if (st.empty() || ch != mapping[st.top()])
                        return false;
                    st.pop();
            }
        }
        return st.size() == 0;
    }
};