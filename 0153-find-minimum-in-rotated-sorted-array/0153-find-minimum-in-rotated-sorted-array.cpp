class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0, h = n - 1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(nums[mid] > nums[n - 1])     l = mid + 1;
            
            else    h = mid - 1;
            
        }
        
        // if(l == n / 2)  return nums[0];
        
        return min(nums[0], nums[l]);
        
    }
};