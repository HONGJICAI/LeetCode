class Solution {
    int stoi(string_view s) {
        uint64_t ret = 0;
        for (auto c: s) {
            ret *= 10;
            ret += c - '0';
            if (ret > INT_MAX) return -2;
        }
        return ret;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<vector<int>> memo(num.size(), vector<int>(num.size(), -1));
        function<uint64_t(string_view, int, int)> getMemo = [&](string_view str, int idx, int len) {            
            if (memo[idx][idx + len - 1] == -1) {
                memo[idx][idx + len - 1] = stoi(str.substr(idx, len));
            }
            return memo[idx][idx + len - 1];
        };
        function<bool(string_view, int, int)> check = [&](string_view str, int i, int j) {
            int l = 0, r = i;
            while (r + j < str.size()) {
                auto lval = getMemo(str, l, i);
                if (lval == -2) return false;
                auto rval = getMemo(str, r, j);
                if (rval == -2) return false;
                auto nextVal = lval + rval;
                if (nextVal > INT_MAX) return false;
                auto next = to_string(nextVal);
                int newr = r + j, newj = next.size();
                if (newr + newj <= str.size()) {                    
                    auto actualVal = getMemo(str, newr, newj);
                    if (actualVal == -2) return false;
                    if (nextVal != actualVal) return false;
                } else return false;
                l = r, i = j;
                r = newr, j = newj;
            }
            return r + j == str.size();
        };
        function<vector<int>(int, int)> take = [&](int i, int j) {
            int l = 0, r = i;
            vector<int> res {memo[l][l + i - 1], memo[r][r + j - 1]};
            while (r + j < num.size()) {
                auto nextVal = memo[l][l + i - 1] + memo[r][r + j - 1];
                res.push_back(nextVal);
                auto next = to_string(nextVal);
                int newr = r + j, newj = next.size();
                l = r, i = j;
                r = newr, j = newj;
            }
            return res;
        };
        for (int i = 1; i < num.size() && i <= 10; ++i) {
            for (int j = 1; i + j + 1 < num.size() && j <= 10; ++j) {
                if (check(num, i, j)) return take(i, j);
                if (num[i] == '0') break;
            }
            if (num[0] == '0') break;
        }
        return {};
    }
};