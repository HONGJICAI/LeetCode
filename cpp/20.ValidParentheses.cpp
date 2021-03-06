class Solution { // 3ms
public:
    bool isValid(string s) {
        if(s.size()%2!=0)return 0;
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(st.empty())return 0;
                switch(s[i]){
                    case ')':if(st.top()!='(')return 0;st.pop();break;
                    case '}':if(st.top()!='{')return 0;st.pop();break;
                    case']':if(st.top()!='[')return 0;st.pop();break;
                }
            }
            else if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            ++i;
        }
        if(!st.empty())return 0;
        return 1;
    }
};
class Solution { // switch table: 4ms
public:
    bool isValid(string s) {
        if(s.size()&1)
            return 0;
        stack<char>st;
        for(int i=0;i<s.size();++i){
            switch(s[i]){
                case ')':
                    if(st.empty()||st.top()!='(')
                        return 0;
                    st.pop();
                    break;
                case '}':
                    if(st.empty()||st.top()!='{')
                        return 0;
                    st.pop();
                    break;
                case']':
                    if(st.empty()||st.top()!='[')
                        return 0;
                    st.pop();
                    break;
                case '(':
                case '{':
                case '[':
                    st.push(s[i]);
                    break;
            }
        }
        return st.empty();
    }
};