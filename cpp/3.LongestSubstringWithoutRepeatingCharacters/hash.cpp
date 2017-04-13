class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int i=0,j=0,max=0,len=s.size();
        for(;j<len;){
            if(hash.find(s[j])==hash.end()){
                hash.insert(s[j]);
                max=max>(j-i+1)?max:(j-i+1);
                j++;
            }
            else{
                hash.erase(s[i++]);
            }
        }
        return max;
    }
};
