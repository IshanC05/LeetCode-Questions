class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n <= 0)   return false;
        
        int x = log2(n);
        int num = pow(2, x);
        
        if((num == n) && (x % 2 == 0))  return true;
        
        return false;
    }
};