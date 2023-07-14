class Solution {
public:

    void solve(vector<int>&nums){
        
        int i, j, n = nums.size();
        
        if(n <= 1)  return;
        
        for(i = n - 2; i >= 0; --i){
            
            if(nums[i] < nums[i + 1])   break;
            
        }
        
        if(i < 0)   reverse(nums.begin(), nums.end());
        
        else{
            
            for(j = n - 1; j >= 0; --j){
                
                if(nums[j] > nums[i]){
                    
                    swap(nums[j], nums[i]);
                    
                    break;
                    
                }
                
            }
            
            reverse(nums.begin() + i + 1, nums.end());
            
        }
        
        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>permSet;
        
        sort(nums.begin(), nums.end());
        
        while(permSet.find(nums) == permSet.end()){
            
            permSet.insert(nums);
            
            solve(nums);
            
        }
        
        vector<vector<int>>ans(permSet.begin(), permSet.end());
        
        return ans;
        
    }
};