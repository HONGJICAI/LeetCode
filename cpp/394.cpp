class Solution {
    // Runtime: 4 ms, faster than 84.37% of C++ online submissions for Decode
    // String. Memory Usage: 8.7 MB, less than 91.46% of C++ online submissions
    // for Decode String.
public:
    string decodeString(string s) {
        function<string(string_view)> recursion = [&recursion](auto s) {
            string res;
            for (int i = 0; i < s.length();)
                if (!isdigit(s[i]))
                    res += s[i++];
                else {
                    int n = 0;
                    while (i < s.length() && isdigit(s[i]))
                        n = n * 10 + s[i++] - '0';
                    int j = i + 1;
                    for (int count = 1; count; ++j)
                        if (s[j] == '[')
                            ++count;
                        else if (s[j] == ']')
                            --count;
                    for (auto t =
                             recursion(s.substr(i + 1, (j - 2) - (i + 1) + 1));
                         n; --n)
                        res += t;
                    i = j;
                }
            return res;
        };
        return recursion(s);
    }
  };