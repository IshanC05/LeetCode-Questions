class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                ans = (abs(nums[i] - nums[j]) == k) ? ++ans : ans;
            }
        }
        return ans;
    }
};