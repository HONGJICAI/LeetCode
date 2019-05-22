class Solution { //16ms
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        auto s=to_string(x);
        return string(s.rbegin(),s.rend())==s;
    }
};