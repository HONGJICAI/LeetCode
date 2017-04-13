class Solution {
public:
    int hash[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
    vector<string> findWords(vector<string>& words) {
        vector <string> res;
        for(string val : words)
        {
            if(val == "") continue;
            int line = val[0] >= 'a'?hash[val[0]-'a']:hash[val[0]-'A'];
            bool flag = true;
            for(char ch : val)
            {
                int h_code = ch >= 'a'?hash[ch-'a']:hash[ch-'A'];
                if(h_code != line)
                {  flag = false; break;}
            }
            if(flag)
                res.push_back(val);
        }
        return res;
    }
};
