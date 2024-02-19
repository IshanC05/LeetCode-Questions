class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n <= 0)  return false;
        
        int ones = 0;
        
        while(n > 0){
            if((n & 1) == 1)   ++ones;
            n = (n >>> 1);
        }
        
        return ones == 1;
    }
}