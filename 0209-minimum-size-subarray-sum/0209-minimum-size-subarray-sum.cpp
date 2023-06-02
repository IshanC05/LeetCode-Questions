class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        int ans = INT_MAX;
        long long sum = 0;
        while(j < n){
            sum = sum + nums[j];
            while(i <= j and sum >= target){
                ans = min(ans, j - i + 1);
                sum = sum - nums[i];
                ++i;
            }
            ++j;
        }
        if(ans == INT_MAX){
            ans = 0;
        }
        return ans;
    }
};