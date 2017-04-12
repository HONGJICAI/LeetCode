class Solution {
public:
	void reverseWords(string &s) {
		int n = s.size() - 1, i, j, k, flag = 1;
		for (i = 0; s[i] == ' '; ++i);
		for (j = n; s[j] == ' '&&j>i; --j);
		for (k = 0; i <= j; ++i)
			if (s[i] == ' ') {
				if (flag == 1)
					s[k++] = s[i];
				flag = 0;
			}
			else {
				s[k++] = s[i];
				flag = 1;
			}
		s.resize(k);
		reverse(s, 0, k-1);
		for (i = j = 0; i<k&&j<k; ++j)
			if (s[j] == ' ') {
				reverse(s, i, j - 1);
				i = j + 1;
			}
		reverse(s, i, j - 1);
	}
	void reverse(string &s, int i, int j) {
		while (i<j) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			++i, --j;
		}
	}
};
