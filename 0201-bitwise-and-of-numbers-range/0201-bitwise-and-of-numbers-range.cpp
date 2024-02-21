class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right)   return left;
        
        long powerOf2 = 1;
        
        while(powerOf2 <= right && powerOf2 <= INT_MAX){
            long prev = powerOf2 - 1;
            if(prev >= left && powerOf2 >= left)    return 0;
            powerOf2 = (powerOf2 << 1);
        }
        
        long res = left;
        
        for(long i = left + 1; i <= right; i++){
            res = (res & i);
        }
        
        return res;
    }
};