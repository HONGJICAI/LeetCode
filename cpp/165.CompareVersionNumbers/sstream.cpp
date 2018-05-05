class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1,ss2;
        ss1<<version1;
        ss2<<version2;
        int a,b;
        char ch;
        while(!ss1.eof()||!ss2.eof()){
            if(!ss1.eof())
                ss1>>a;
            if(!ss2.eof())
                ss2>>b;
            if(a>b)
                return 1;
            else if(a<b)
                return -1;
            ss1>>ch;
            ss2>>ch;
            a=0;
            b=0;
        }
        return 0;
    }
};
