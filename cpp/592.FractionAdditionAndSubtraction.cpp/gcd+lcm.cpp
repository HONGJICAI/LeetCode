class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        int a,b,suma=0,sumb=1;
        char ch;
        while(ss>>a>>ch>>b){
            int _lcm=lcm(b,sumb);
            suma*=_lcm/sumb;
            sumb=_lcm;
            a*=_lcm/b;
            suma+=a;
            int _gcd=gcd(suma,sumb);
            suma/=_gcd;
            sumb/=_gcd;
        }
        if(suma*sumb<0)
            return "-"+to_string(abs(suma))+"/"+to_string(abs(sumb));
        return to_string(abs(suma))+"/"+to_string(abs(sumb));
    }
    int gcd(int a, int b)  {  
        if(a < b)  
            return gcd(b,a);
        int temp;  
        while(b != 0){  
            temp = a % b;  
            a = b;  
            b = temp;  
        }  
        return a;  
    }  
    int lcm(int a, int b)  {  
        return a * b / gcd(a, b);
    }  
};
