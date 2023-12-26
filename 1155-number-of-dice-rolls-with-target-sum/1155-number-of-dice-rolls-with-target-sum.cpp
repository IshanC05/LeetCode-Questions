class Solution {
public:
    int M = 1e9+7;
    
    int t[31][1001];
    
    int helper(int n, int target, int k){
        if(target < 1)  return 0;
        
        if(n == 1)  return (target <= k) ? 1 : 0;
        
        if(t[n][target] != -1)  return t[n][target];
        
        int res = 0;
        
        for(int i = 1; i <= k; i++){
            res = (res + helper(n - 1, target - i, k)) % M;
        }
        
        return t[n][target] = res;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(t, -1, sizeof(t));
        return helper(n, target, k);
    }
};