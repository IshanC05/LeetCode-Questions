class Solution {
public:
    int getBits(int n){
        
        int count = 0;
        
        while(n){
            
            if(n & 1)   ++count;
            
            n = (n >> 1); 
            
        }
        
        return count;
        
    }
    
    vector<int> countBits(int n) {
        
        vector<int>ans(n + 1, 0);
        
        for(int i = 0; i <= n; i++){
            
            ans[i] = getBits(i);
            
        }
        
        return ans;
        
    }
};