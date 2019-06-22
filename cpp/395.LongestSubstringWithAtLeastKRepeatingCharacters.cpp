class Solution {
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
//Memory Usage: 8.8 MB, less than 74.27% of C++ online submissions for Longest Substring with At Least K Repeating Characters.
public:
    int longestSubstring(string s, int k) {
        int ret=0;
        function<void(string_view)> dfs=[&](string_view ss){
            if(not ss.size()) return;
            unordered_map<char,int>counter;
            for(auto ch:ss)
                ++counter[ch];
            for(auto it=counter.begin();it!=counter.end();)
                if(it->second>=k)
                    counter.erase(it++);
                else
                    ++it;
            if(counter.size()){
                int start=0;
                for(int i=0;i<ss.size();++i)
                    if(counter.count(ss[i])){
                        if(i-start>ret)
                            dfs(ss.substr(start,i-start));
                        start=i+1;
                    }
                dfs(ss.substr(start));
            }
            else
                ret=max(ret,(int)ss.size());
        };
        dfs(s);
        return ret;
    }
};