class Solution {
public:
    int calculateGoodSubarraysTillK(vector<int>&nums, int k){
        int n = nums.size(), ans = 0;
        int i = 0, j = 0;
        unordered_map<int, int>mp;
        
        while(j < n){
            ++mp[nums[j]];
            while(mp.size() > k){
                --mp[nums[i]];
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                ++i;
            }
            ans = ans + (j - i + 1);
            ++j;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {        
        int tillK = calculateGoodSubarraysTillK(nums, k);
        int tillK_1 = calculateGoodSubarraysTillK(nums, k - 1);
        return tillK - tillK_1;
    }
};