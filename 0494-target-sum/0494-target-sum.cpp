class Solution {
public:
    int countSubsets(vector<int>& arr, int sum, int n){
        const int mod = 1e9+7;
    
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));
    
        for(int i = 0; i <= n; i++)
            t[i][0] = 1;
    
        for(int j = 1; j <= sum; j++)
            t[0][j] = 0;
    
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
    
                t[i][j] = t[i - 1][j] % mod;
    
                if(arr[i - 1] <= j){
                    t[i][j] = (t[i - 1][j - arr[i - 1]] + t[i][j]) % mod;
                }
            }
        }
    
        return t[n][sum] % mod;
    }

    
    int findTargetSumWays(vector<int>& arr, int target) {
        
        int sum = 0, n = arr.size();
        
        for(int i : arr)    
            sum += i;
        
        int targetSum = (sum + target);
        
        if(sum < target || (sum + target) < 0 || ((sum + target) % 2) != 0) return 0;
        
        targetSum /= 2;
        
        return countSubsets(arr, targetSum, n);     
    }
};