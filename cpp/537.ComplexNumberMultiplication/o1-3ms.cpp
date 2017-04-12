class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		stringstream ss;
		int a1, a2, b1, b2;
		int off = a.find('+');
		a1=stoi( a.substr(0,off) );
		a2=stoi( a.substr(off+1,a.size()-off-1) );
		off = b.find('+');
		b1=stoi( b.substr(0,off) );
		b2=stoi( b.substr(off+1,b.size()-off-1) );
		int c1 = a1*b1 - a2*b2, c2 = a1*b2 + a2*b1;
        return to_string(c1)+"+"+to_string(c2)+"i";
    }
};
