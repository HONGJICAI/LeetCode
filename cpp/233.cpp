class Solution {
    /*
    For any input like 2045, we try to calculate
        count_1([0,2045]) = count_1((45,2045]) + count_1((5,45]) + count_1((0,5])
    For (45, 2045), we notice that it has two rule
        thousands place: count_1(n) = n >= 2000 ? 1000 : n - 1000 + 1
                         count_1(2045) = 1000
        hundres/tens/units place: count_1(2045) = 2 * 1000 / 10                                  
                                  count_1(n) = to_string(n)[0] * 10^(to_string(n).size()-2)
        count_1([0,2045]) = 1000 + 3 * 200
    */
    int impl(const string_view& sv, int n) {
        if (sv.size() == 1) {
            return sv[0] > '0';
        }
        auto ignoreHighest = pow(10, sv.size() - 2) * (sv.size() - 1) * (sv[0] - '0');
        auto highest = sv[0] > '1' ? pow(10, sv.size() - 1) : n - pow(10, sv.size() - 1) + 1;
        auto it = find_if(sv.begin() + 1, sv.end(), [](char ch) {
            return ch != '0';
        });
        auto remainingStr = it != sv.end() ? sv.substr(it - sv.begin()) : "";
        auto remainingVal = n - pow(10, sv.size() - 1) * (sv[0] - '0');
        auto remaining = remainingStr.size() ? impl(remainingStr, remainingVal) : 0;
        return ignoreHighest + highest + remaining;
    }
public:
    int countDigitOne(int n) {
        return impl(to_string(n), n);
    }
};