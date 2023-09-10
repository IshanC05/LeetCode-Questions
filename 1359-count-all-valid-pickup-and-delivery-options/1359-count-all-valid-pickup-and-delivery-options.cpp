class Solution {
public:
    int countOrders(int n) {
        
        int mod = 1e9+7;
    
        if(n == 1)  return 1;
        
        long long int res = 1;
        
        for(int i = 2; i <= n; i++){
            
            int spaces = 2 * i - 1;
            
            int pos = (spaces * (spaces + 1)) / 2;
            
            res = (res * pos) % mod;
            
        }
        
        return res;
        
    }
};