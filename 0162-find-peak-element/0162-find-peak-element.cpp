class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1)  return 0;
        
        int l = 0, h = nums.size() - 1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            int a = mid - 1 == -1 ? INT_MIN : nums[mid - 1];
            int c = mid + 1 == n ? INT_MIN : nums[mid + 1];
            
            if(nums[mid] > a && nums[mid] > c)  return mid;
            
            else if(nums[mid] < c)  l = mid + 1;
            
            else    h = mid - 1;
            
        }
        
        return -1;
        
    }
};