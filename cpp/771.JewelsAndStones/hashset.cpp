class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res=0;
        unordered_set<char>hashset(J.begin(),J.end());
        for(char ch:S)
            if(hashset.find(ch)!=hashset.end())
                ++res;
        return res;
    }
};
