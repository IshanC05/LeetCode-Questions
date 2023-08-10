class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int n = nums.size(), i = 0, j = 0, ans = 0;
        
        if(n == 1)  return 0;
        
        sort(nums.begin(), nums.end());
        
        while(i < n && j < n){
            
            if(i == j){
                
                ++j;
                
                continue;
                
            }
            
            int diff = nums[j] - nums[i];
            
            if(diff == k){
                
                ++ans;
                
                while(j < n && (nums[j] - nums[i] == k)){
                    
                    ++j;
                    
                }
                
                if(j == n)  return ans;
            }
            
            else if(diff > k)  ++i;
            
            else    ++j;
            
        }
        
        return ans;
        
    }
};