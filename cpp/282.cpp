class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        string s, temp(1, num[0]);
        function<void(int, long, bool, char, int)> dfs = [&](int idx, long total, bool isPreOp, char lastOp, int base) {
            if (idx == num.size()) {
                auto tempVal = stol(temp);
                if (total + base * tempVal == target)
                    ret.push_back(s + temp);
                return;
            }
            
            if (temp.size() == 1 && temp[0] == '0') {
            } else {
                temp += num[idx];
                dfs(idx + 1, total, false, lastOp, base);
                temp.pop_back();
            }

            if (!isPreOp) {
                auto tempBk = temp;
                auto tempVal = stol(temp);     
                s += temp;
                temp = "";
                for (auto op: string("+-*")) {
                    s += op;
                    switch (op) {
                        case '+': dfs(idx, total + base * tempVal, true, op, 1); break;
                        case '-': dfs(idx, total + base * tempVal, true, op, -1); break;
                        case '*': dfs(idx, total, true, lastOp, base * tempVal); break;
                    }
                    s.pop_back();
                }
                temp = move(tempBk);
                s.erase(s.size() - temp.size());
            }
        };
        dfs(1, 0, false, '+', 1);
        return ret;
    }
};