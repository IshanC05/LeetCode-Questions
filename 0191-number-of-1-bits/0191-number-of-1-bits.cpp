class Solution {
public:
    int hammingWeight(uint32_t n) {
     
        int ans = 0;
        
        while(n){
            
            int bit = (n & 1);
            
            ans = bit == 1 ? ++ans : ans;
            
            n = (n >> 1);
            
        }
        
        return ans;
        
    }
};