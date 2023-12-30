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
        ll r = rightIdx;
        
        for(ll l = 0; l <= leftIdx; l++){
            while(r < n && nums[l] >= nums[r])
                ++r;
            res += (n - r + 1);
        }
        
        return res;
    }
};