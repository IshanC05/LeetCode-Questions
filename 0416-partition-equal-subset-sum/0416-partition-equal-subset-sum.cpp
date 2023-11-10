class Solution {
public:
    int t[201][20001];
    bool helper(vector<int>& nums, int sum, int n){
       
        if(n == 0)   return sum == 0;
        
        if(t[n][sum] != -1)     return t[n][sum];
        
        bool take = false, skip = false;
        
        if(nums[n - 1] <= sum){
            take = helper(nums, sum - nums[n - 1], n - 1);
        }
        
        skip = helper(nums, sum, n - 1);
        
        return t[n][sum] = (take || skip);
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for(int i : nums)   sum += i;
        
        if(sum & 1)     return false;
        
        memset(t, -1, sizeof(t));
        
        return helper(nums, sum / 2, n);        
    }
};