class Solution {
public:
    vector<vector<int>>ways = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1 ,3}, {2, 4}};
    
    int mod = 1e9+7;
    
    long long t[50001][10];
    
    int helper(int n, int u){
        
        if(n == 0)  return 1;
        
        if(t[n][u] != -1)   return t[n][u];
        
        long long smallAns = 0;
        
        for(int v : ways[u]){
            
            smallAns = (smallAns + helper(n - 1, v)) % mod; 
            
        }
        
        return t[n][u] = smallAns;
        
    }
    
    int knightDialer(int n) {
        
        memset(t, -1, sizeof(t));
        
        long long res = 0;
        
        for(int i = 0; i < 10; i++){
            
            res = (res + helper(n - 1, i)) % mod;
            
        }
        
        return res;
        
    }
};