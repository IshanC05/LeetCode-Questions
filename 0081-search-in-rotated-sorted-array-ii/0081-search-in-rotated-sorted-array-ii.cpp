class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int l = 0, h = nums.size() - 1;
        
        while(l <= h){
            
            while(l < h && nums[l] == nums[l + 1])  ++l;
            
            while(h > l && nums[h] == nums[h - 1])  --h;
            
            int mid = l + (h - l) / 2;
            
            if(nums[mid] == target)     return true;
            
            else if(nums[mid] >= nums[l]){
                
                if(target >= nums[l] && target < nums[mid]) h = mid - 1;
                
                else    l = mid + 1;
                
            }
            
            else{
                
                if(target <= nums[h] && target > nums[mid]) l = mid + 1;
                
                else    h = mid - 1;
                
            }
            
        }
        
        return false;
        
    }
};