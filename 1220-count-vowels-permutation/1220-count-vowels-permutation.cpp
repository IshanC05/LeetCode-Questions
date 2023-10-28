class Solution {
public:
    int mod = 1e9+7;
    int dp[100001][6];
    unordered_map<char,int>mp;
    long long dfs(int i, int n, char prev){
        
        if(i >= n)  return 0;
        
        if(i == n - 1)      return 1;
        
        if(dp[i][mp[prev]] != -1)   return dp[i][mp[prev]];
        
        if(prev == 'a')
            return dp[i][mp[prev]] = (dfs(i + 1, n, 'e')) % mod;
        
        if(prev == 'e')
            return dp[i][mp[prev]] = (dfs(i + 1, n, 'a')% mod + dfs(i + 1, n, 'i')% mod) % mod;
        
        if(prev == 'i'){
            return dp[i][mp[prev]] = (dfs(i + 1, n, 'a')% mod + dfs(i + 1, n, 'e')% mod + dfs(i + 1, n, 'o')% mod + dfs(i + 1, n, 'u')% mod) % mod;
        }
        if(prev == 'o')
            return dp[i][mp[prev]] = (dfs(i + 1, n, 'i')% mod + dfs(i + 1, n, 'u')% mod) % mod;
            
        if(prev == 'u')
            return dp[i][mp[prev]] = (dfs(i + 1, n, 'a')) % mod;
            
        return 0;
    }
    
    int countVowelPermutation(int n) {
        
        long long i = 0, res = 0;
        
        mp.clear();
        
        mp['a'] = 1;
        mp['e'] = 2;
        mp['i'] = 3;
        mp['o'] = 4;
        mp['u'] = 5;
        
        memset(dp, -1, sizeof(dp));
        
        res += dfs(i, n, 'a') % mod;
        res += dfs(i, n, 'e') % mod;
        res += dfs(i, n, 'i') % mod;
        res += dfs(i, n, 'o') % mod;
        res += dfs(i, n, 'u') % mod;
        
        return (res % mod);
    }
};