class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0, j = 0, ans = INT_MAX, n = nums.size();
        long long sum = 0;
        
        while(j < n){
        
            sum += nums[j];
            
            while(i <= j && sum >= target){
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
            
            ++j;

        }
        
        if(ans == INT_MAX)  ans = 0;
        
        return ans;
    }
};