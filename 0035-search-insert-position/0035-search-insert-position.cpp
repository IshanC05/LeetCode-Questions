class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l = 0, h = nums.size() - 1, idx = -1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(nums[mid] == target) return mid;
            
            else if(nums[mid] > target){
                
                idx = mid;
                
                h = mid - 1;
                
            }else   l = mid + 1;
            
        }
        
        return (idx == -1) ? ((target < nums[0]) ? 0 : nums.size()) : idx;
        
    }
};