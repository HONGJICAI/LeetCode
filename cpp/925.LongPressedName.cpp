class Solution {
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Long Pressed Name.
//Memory Usage: 8.4 MB, less than 85.38% of C++ online submissions for Long Pressed Name.
public:
    bool isLongPressedName(string_view name, string_view typed) {
        int i=0,j=0;
        while(i<name.size()&&j<typed.size()){
            if(name[i]!=typed[j])
                return false;
            while(i<name.size()&&j<typed.size()&&name[i]==typed[j])
                ++i,++j;
            if(i>0&&name[i-1]==name[i])
                return false;
            while(j<typed.size()&&name[i-1]==typed[j])
                ++j;
        }
        return i==name.size() and j==typed.size();
    }
};