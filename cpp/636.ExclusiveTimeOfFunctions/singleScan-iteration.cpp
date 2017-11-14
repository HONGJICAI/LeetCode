class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>res(n,0);
        int lastTime=0,lastId=0;
        vector<int>st(1,0);
        for(auto &str:logs){
            int first=str.find(':'),second=str.rfind(':');
            int id=stoi(str.substr(0,first));
            bool end=second-first==4;//sizeof(":end:")-1;
            int timestamp=stoi(str.substr(second+1));
            if(end){
                res[id]+=timestamp-lastTime+1;
                lastTime=timestamp+1;
                st.pop_back();
            }
            else{
                res[st.back()]+=timestamp-lastTime;
                lastTime=timestamp;
                st.push_back(id);
            }
        }
        return res;
    }
};
