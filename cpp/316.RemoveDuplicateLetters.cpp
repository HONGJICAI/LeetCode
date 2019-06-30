class Solution {
//Runtime: 8 ms Your runtime beats 40.32 % of cpp submissions.
//Memory Usage: 10.6 MB
public:
    string removeDuplicateLetters(string s) {
        array<int,26> cnt={};
        int pos = 0; // the position for the smallest s[i]
        for (auto ch:s)
            cnt[ch - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < s[pos])
                pos = i;
            if (--cnt[s[i] - 'a'] == 0)
                break;
        }
        string next{};
        for(int i=pos+1;i<s.size();++i)
            if(s[i]!=s[pos])
                next+=s[i];
        return s.size() == 0 ? "" : s[pos] + removeDuplicateLetters(next);
    }
};