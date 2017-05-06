class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),maxlen=0,count=0;
        vector<bool>res(n,0);
        stack<int>st;
        for(int i=0;i<n;++i)
            if(s[i]=='(')
                st.push(i);
            else if(!st.empty()){
                res[st.top()]=res[i]=true;
                st.pop();
            }
        for(int i=0;i<n;++i)
            if(res[i]==true)
                maxlen=max(++count,maxlen);
            else
                count=0;
        return maxlen;
    }
};
