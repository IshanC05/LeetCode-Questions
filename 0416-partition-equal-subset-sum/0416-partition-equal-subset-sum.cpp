class Solution {
public:
    bool helper(vector<int>& arr, int sum){
       
        int n = arr.size();
        int t[n + 1][sum + 1];
        
        for(int i = 0; i <= n; i++)
            t[i][0] = 1;
            
        for(int j = 1; j <= sum; j++)
            t[0][j] = 0;
            
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                
                t[i][j] = t[i - 1][j];
                
                if(arr[i - 1] <= j){
                    
                    t[i][j] = max(t[i - 1][j - arr[i - 1]], t[i][j]);
                    
                }
            }
        }
        
        return t[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for(int i : nums)   sum += i;
        
        if(sum & 1)     return false;
        
        return helper(nums, sum / 2);        
    }
};