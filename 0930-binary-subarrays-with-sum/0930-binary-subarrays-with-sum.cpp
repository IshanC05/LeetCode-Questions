class Solution {
public:
    int helper(vector<int>& nums, int goal){
        int i = 0, j = 0, n = nums.size();
        int sum = 0, res = 0;
        
        while(j < n){
            sum += nums[j];
            
            while(sum > goal && i <= j){
                sum -= nums[i++];
            }
            
            res += (j - i + 1);
            ++j;
        }
        
        return res;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};