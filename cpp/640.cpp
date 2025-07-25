class Solution {
public:
    string solveEquation(string equation) {
        auto l = make_pair(0, 0);
        auto r = l;
        auto cur = &l;
        string number;
        char op = '+';
        auto handleNumber = [&]() {
            if (number.size() > 0) {
                auto num = stoi(number);
                number = "";
                cur->second += op == '-' ? -num : num;
            }
        };
        for (auto ch: equation) {
            switch (ch) {
                case '=': {
                    handleNumber();
                    cur = &r;
                    op = '+';
                    break;
                }
                case '+':
                case '-': 
                    handleNumber();
                    op = ch;
                    break;
                case 'x': {
                    auto k = number.size() > 0 ? stoi(number) : 1;
                    number = "";
                    cur->first += op == '-' ? -k : k;
                    break;
                }
                default: {
                    number += ch;
                }
            }
        }
        handleNumber();
        l.first -= r.first;
        r.second -= l.second;
        if (r.second == 0) return l.first == 0 ? "Infinite solutions" : "x=0";
        if (l.first == 0) return r.second == 0 ? "Infinite solutions" : "No solution";
        return "x=" + to_string(r.second / l.first);
    }
};