class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), ans = 0;
        long long prod = 1;
        while(j < n){
            prod = prod * nums[j];
            while(prod >= k and i <= j){
                prod = prod / nums[i];
                ++i;
            }
            ans = ans + (j - i + 1);
            ++j;
        }
        return ans;
    }
};