class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size(), l = 0, h = n - 1;
        
        if(n == 1)  return nums[h];
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])){
                
                l = mid + 1;
                
            }
            
            else    h = mid - 1;   
            
        }
        
        return nums[l];
        
    }
};