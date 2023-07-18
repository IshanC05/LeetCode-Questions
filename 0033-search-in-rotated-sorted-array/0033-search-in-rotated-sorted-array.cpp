class Solution {
public:
    
    int binarySearch(vector<int>&arr, int l, int h, int k){
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(arr[mid] == k)   return mid;
            
            else if(arr[mid] > k)   h = mid - 1;
            
            else l = mid + 1;
        }
        
        return -1;
        
    }
    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size(), l = 0, h = n - 1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(nums[mid] > nums[n - 1]) l = mid + 1;
            
            else h = mid - 1;
            
        }
        
        int ans = binarySearch(nums, 0, l - 1, target);
        
        if(ans == -1)   ans = binarySearch(nums, l, n - 1, target);
        
        return ans;     
        
    }
};