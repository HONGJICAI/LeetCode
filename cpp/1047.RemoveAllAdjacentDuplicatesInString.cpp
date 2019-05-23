class Solution { //344ms recursion
public:
    string removeDuplicates(string S) {
        int i=-1,j=1;
        for(;j<S.size();++j){
            if(S[j-1]==S[j]){
                i=j-1;
                ++j;
                break;
            }
        }
        return i==-1?S:removeDuplicates(S.substr(0,i)+S.substr(j));
    }
};
class Solution { //24ms iteration
public:
    string removeDuplicates(string S) {
        stack<int>st;
        vector<bool>deleted(S.size());
        for(int i=0;i<S.size();++i){
            if(!st.empty()&&S[st.top()]==S[i]){
                deleted[st.top()]=deleted[i]=true;
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        string ret;
        for(int i=0;i<S.size();++i){
            if(!deleted[i])
                ret+=S[i];
        }
        return ret;
    }
};