class Solution { //0ms
public:
    int fib(int N) {
        int a=0,b=1;
        while(N--){
            int c=a+b;
            a=b;
            b=c;
        }
        return a;
    }
};