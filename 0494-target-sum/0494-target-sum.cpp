class Solution {
public:
    int helper(vector<int>& arr, int sum, int n){
        
        if(n == 0)  return (sum == 0 ? 1 : 0);
        
        int res = 0;
        
        res += helper(arr, sum + arr[n - 1], n - 1);
        
        res += helper(arr, sum - arr[n - 1], n - 1);
        
        return res;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        return helper(nums, target, n);        
    }
};