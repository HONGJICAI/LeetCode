class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1, j = b.size() - 1;
        char c = 0;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s += (char)(c % 2 + '0');
            c /= 2;
        }
        return {s.rbegin(), s.rend()};
    }
};
