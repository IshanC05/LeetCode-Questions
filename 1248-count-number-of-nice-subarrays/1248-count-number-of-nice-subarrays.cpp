class Solution {
public:
    int solve(vector<int>&nums, int k){
        unordered_map<int,int>mp;
        int ans = 0, oddCount = 0;
        int i = 0, n = nums.size();
        for(int j = 0; j < n; j++){
            ++mp[nums[j]];
            oddCount = (nums[j] & 1) ? ++oddCount : oddCount;
            while(oddCount > k){
                --mp[nums[i]];
                oddCount = (nums[i] & 1) ? --oddCount : oddCount;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                ++i;
            }
            ans = ans + (j - i + 1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int countTillK = solve(nums, k);
        int countTillK_1 = solve(nums, k - 1);
        return countTillK - countTillK_1;
    }
};