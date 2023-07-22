class Solution {
public:
    int arrangeCoins(int n) {
        
        long l = 1, h = n;
        
        long rows, coinsReq;
        
        while(l <= h){
            
            rows = l + (h - l) / 2;
            
            coinsReq = rows * (rows + 1) / 2;
            
            if(coinsReq == n)   return rows;
            
            else if(coinsReq > n)   h = rows - 1;
            
            else    l = rows + 1;
            
        }
        
        return h;
        
    }
};