class Solution {
public:
    int compress(vector<char>& chars) {
        int anchor = 0, write = 0;
        for (int read = 0; read < chars.size(); read++) {
            if (read + 1 == chars.size() || chars[read + 1] != chars[read]) {
                chars[write++] = chars[anchor];
                if (read > anchor) {
                    string num=to_string(read-anchor+1);
                    memcpy(&chars[write],&num[0],num.size());
                    write+=num.size();
                }
                anchor = read + 1;
            }
        }
        return write;
    }
};
