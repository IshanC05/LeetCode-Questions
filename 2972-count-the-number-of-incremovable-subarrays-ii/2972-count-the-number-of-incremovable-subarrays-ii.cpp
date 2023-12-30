#define ll long long int

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        
        ll n = nums.size();
        ll leftIdx = 0, rightIdx = n - 1;
        
        while(leftIdx + 1 < n && nums[leftIdx] < nums[leftIdx + 1])
            ++leftIdx;
        
        while(rightIdx - 1 >= 0 && nums[rightIdx] > nums[rightIdx - 1])
            --rightIdx;
        
        if(leftIdx == n - 1)    return (n * (n + 1)) / 2;
        
        ll res = (n - rightIdx + 1);
        
        for(ll i = 0; i <= leftIdx; i++){
            ll ubIdx = upper_bound(nums.begin() + rightIdx, nums.end(), nums[i]) - nums.begin();
            res += (n - ubIdx + 1);
        }
        
        return res;
    }
};