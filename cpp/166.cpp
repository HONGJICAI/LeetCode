class Solution {    
    string impl(long long numerator, long long denominator) {        
        auto result = numerator / denominator;
        if (result * denominator == numerator)
            return to_string(result);
        unordered_map<long long, long long> meet;
        string res;
        int pos = 0;
        for (numerator -= result * denominator; numerator != 0;) {
            do {
                if (auto it = meet.find(numerator); it != meet.end()) {
                    res = res.substr(0, it->second) + '(' +
                          res.substr(it->second) + ')';
                    return to_string(result) + "." + res;
                }
                meet[numerator] = pos++;
                numerator *= 10;
                res += "0";
            } while (numerator < denominator);
            auto result = numerator / denominator;
            res[res.size() - 1] += result;
            numerator -= result * denominator;
        }
        return to_string(result) + "." + res;
    }
  public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg=false;
        if((numerator<0&&denominator>0)||(numerator>0&&denominator<0)){
            neg=true;
        }
        return (neg ? "-" : "") + impl(abs(numerator), abs(denominator));
    }
};