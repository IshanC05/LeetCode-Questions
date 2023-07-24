class Solution {
public:
    double myPow(double x, int n) {
        
        if(n == 0)  return 1;
        
        if(n == 1)  return x;
        
        double temp = myPow(x, abs(n / 2));
        
        temp = temp * temp;
        
        if(n % 2 != 0)  temp = temp * x;
        
        if(n < 0)   temp = 1 / temp;
        
        return temp;
        
    }
};