class Solution {
public:
    vector<string> fullJustify(vector<string> words, int maxWidth) {
        vector<string> res;
        for(int i = 0, j = 0, curLen = 0; i < words.size(); i = j, curLen = 0) {
            while (j < words.size() && words[j].size() + curLen + j - i <= maxWidth) {
                curLen += words[j++].size();
            }
            if (j < words.size() && j - i > 1) {
                vector<int> spaces(j - i - 1, 1);
                for (int k = 0; k < (maxWidth - curLen) - spaces.size(); ++k) {
                    spaces[k % spaces.size()]++;
                }
                string line = words[i];
                for (int k = i + 1; k < j; ++k) {
                    line += string(spaces[k - i - 1], ' ') + words[k];
                }
                res.push_back(line);
            } else {
                string line = words[i];
                for (int k = i + 1; k < j; ++k) {
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
                res.push_back(line);
            }
        }
        return res;
    }
};