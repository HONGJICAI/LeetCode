class Solution {
    void tryPop(vector<int> &digits, vector<char>& ops) {        
        if (ops.size() == 0)
            return;
        auto b = digits.back();
        digits.pop_back();
        auto op = ops.back();
        ops.pop_back();
        auto a = 0;
        if (digits.size() != 0) {
            a = digits.back();
            digits.pop_back();
        }
        auto c = op == '+' ? a + b : a - b;
        digits.push_back(c);
    }
public:
    int calculate(string s) {
        string digit;
        vector<vector<int>> digits = { {} };
        vector<vector<char>> ops = { {} };
        auto handleNewDigit = [&](){            
            if (digit.size() > 0) {
                digits.back().push_back(stoi(digit));
                digit = "";                    
                tryPop(digits.back(), ops.back());
            }
        };
        for (auto ch: s) {
            if (ch == '(') {
                ops.push_back({});
                digits.push_back({});
            } else if (ch == ')') {
                handleNewDigit();
                auto val = digits.back().back();
                ops.pop_back();
                digits.pop_back();
                digits.back().push_back(val);
                tryPop(digits.back(), ops.back());
            } else if (ch == '+' || ch == '-'){
                handleNewDigit();
                ops.back().push_back(ch);
            } else if (ch == ' '){
                continue;
            } else {
                digit += ch;
            }
        }
        handleNewDigit();
        return digits.back().back();
    }
};