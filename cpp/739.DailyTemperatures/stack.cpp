class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();++i){
            while(st.size()&&st.top().second<temperatures[i]){
                int index=st.top().first;
                res[index]=i-index;
                st.pop();
            }
            st.push(make_pair(i,temperatures[i]));
        }
        return res;
    }
};
