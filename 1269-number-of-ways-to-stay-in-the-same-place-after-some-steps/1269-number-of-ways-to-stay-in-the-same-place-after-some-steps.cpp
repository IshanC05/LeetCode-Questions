class Solution {
public:
    int M = 1e9+7;
    
    vector<vector<int>>t;
    
    int helper(int steps, int len, int idx){
        
        if(idx < 0 || idx >= len)   return 0;
        
        if(steps == 0)  return idx == 0 ? 1 : 0;
        
        if(t[steps][idx] != -1)     return t[steps][idx];
        
        int res = 0;
        
        res = (res + helper(steps - 1, len, idx + 1)) % M;
        
        res = (res + helper(steps - 1, len, idx - 1)) % M;
        
        res = (res + helper(steps - 1, len, idx)) % M;
        
        return t[steps][idx] = res;
    }

    int numWays(int steps, int arrLen) {
        
        arrLen = min(arrLen, steps);
        
        t = vector<vector<int>>(steps + 1, vector<int>(arrLen, -1));
        
        return helper(steps, arrLen, 0);
    }
};