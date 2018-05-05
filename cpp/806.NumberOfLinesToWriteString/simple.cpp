class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int used=0,line=1;
        for(auto ch:S){
            used+=widths[ch-'a'];
            if(used>100){
                ++line;
                used=widths[ch-'a'];
            }
        }
        return vector<int>{line,used};
    }
};
