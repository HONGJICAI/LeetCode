class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        vector<string>temp;
        for(int i=1;i<=n;++i){
            temp.emplace_back(std::move(to_string(i)));
        }
        sort(temp.begin(),temp.end());
        for(auto &str:temp)
            res.emplace_back(stoi(str));
        return res;
    }
};
