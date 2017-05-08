class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int s1s[26] = {};
		int n = s1.size(), off = 0;
		for (int i = 0; i<n; ++i)
			++s1s[s1[i] - 'a'];
		for (int i = 0; i + off<s2.size();) {
			if (s1s[s2[i + off] - 'a']>0) {
				s1s[s2[i + off] - 'a']--;
				--n;
				++off;
				if (n == 0)
					return 1;
			}
			else {
			    if(off>0){
				    s1s[s2[i] - 'a']++;
					--off;
					++n;
			    }
				++i;
			}
		}
		return 0;
	}
};
