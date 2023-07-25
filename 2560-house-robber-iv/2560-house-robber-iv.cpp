class Solution {
public:
    bool helper(vector<int>&arr, int target, int k){
        
        int i = 0;
        
        while(i < arr.size()){
            
            if(arr[i] <= target){
                
                --k;
                
                i += 2;
                
            }
            
            else    ++i;
            
            if(k == 0)  return true;
            
        }
        
        return k == 0;
        
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        int l = 1, h = INT_MAX, ans = INT_MAX;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(helper(nums, mid, k)){
                
                ans = min(ans, mid);
                
                h = mid - 1;
                
            }
            
            else   l = mid + 1;
            
        }
        
        return ans;
        
    }
};