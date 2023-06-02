class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size(), ans = 0;
        long long prod = 1;
        for(int j = 0; j < n; j++){
            prod = prod * nums[j];
            while(prod >= k and i <= j){
                prod = prod / nums[i++];
            }
            ans = ans + (j - i + 1);
        }
        return ans;
    }
};