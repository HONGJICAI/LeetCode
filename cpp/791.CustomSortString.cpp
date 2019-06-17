class Solution {
//Runtime: 4 ms, faster than 84.35% of C++ online submissions for Custom Sort String.
//Memory Usage: 8.6 MB, less than 37.47% of C++ online submissions for Custom Sort String.
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> dir;
        for (int i = 0; i < S.size(); ++i) 
            dir[S[i]]=i;
        sort(T.begin(), T.end(),[&](char a, char b) {
            return dir[a] < dir[b]; 
        });
        return T;
    }
};