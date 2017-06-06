class Solution {
public:
	int findNthDigit(int n) {
		int len = 1;
		for (long long int base = 9; n - base>0; ++len) {
			n -= base;
			base = base * 10 * (len + 1) / len;
		}
		int target = pow(10, len - 1);
		int off = (n-1)%len;
		target = target + (n-1) / len;
		for (int i = 0; i<len - off - 1; ++i)
			target /= 10;
		return target % 10;
	}
};
