class Solution {
public:
    int magicalString(int n) {
        string sub = "122112122122";
        string gen = "1221121221221121122";
        while (gen.size() < n) {
            auto cnt = gen[sub.size()];
            auto ch = gen[gen.size() - 1] == '1' ? '2' : '1';
            gen.append(cnt - '0', ch);
            sub += cnt;
        }
        return count(gen.begin(), gen.begin() + n, '1');
    }
};