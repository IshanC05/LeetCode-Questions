class Solution {
public:
    
    bool helper(vector<int>&arr, int k, int target){
        
        int parts = 1, sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(arr[i] > target)     return false;
            
            if(sum + arr[i] > target){
                
                ++parts;
                
                sum = arr[i];
                
            }
            
            else    sum += arr[i];
            
            if(parts > k)   return false;
            
        }
        
        return true;
        
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int l = 0, h = accumulate(nums.begin(), nums.end(), 0), ans = h;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(helper(nums, k, mid)){
                
                ans = min(mid, ans);
                
                h = mid - 1;
                
            }
            
            else    l = mid + 1;
            
        }
        
        return ans;
        
    }
};