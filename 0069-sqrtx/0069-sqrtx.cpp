class Solution {
public:
    int mySqrt(int x) {
        
        int l = 1, h = x;
        
        long square;
        
        while(l <= h){
            
            long mid = l + (h - l) / 2;
            
            square = mid * mid;
            
            if(square == x)     return mid;
            
            else if(square > x)     h = mid - 1;
            
            else    l = mid + 1;
            
        }
        
        return h;
        
    }
};