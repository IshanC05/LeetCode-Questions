class Solution {
public:
    int M = 1e9+7;
    int t[1001][1001];
    int helper(int n, int k){
        if(k == 0)  return 1;
        if(n == 0 ) return 0;   
        
        if(t[n][k] != -1)   return t[n][k];
    
        long long res = 0;
        
        for(int inv = 0; inv <= min(k, n - 1); inv++){
            res = res + helper(n - 1, k - inv);
            res = res % M;
        }
        
        return t[n][k] = res;
    }
    
    int kInversePairs(int n, int k) {
        memset(t, -1, sizeof(t));
        return helper(n, k);
    }
};