class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int l = 1, h = num;
        
        long square;
        
        while(l <= h){
            
            long mid = l + (h - l) / 2;
            
            square = mid * mid;
            
            if(square == num)   return true;
            
            else if(square > num)   h = mid - 1;
            
            else    l = mid + 1;
            
        }
        
        return false;
        
    }
};