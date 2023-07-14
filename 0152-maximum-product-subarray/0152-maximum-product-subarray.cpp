class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int prefix = 0, suffix = 0, maxAns = nums[0], n = nums.size();
	    
	    for(int i = 0; i < n; i++){
	        
            prefix =  (prefix ? prefix : 1) * nums[i];
            
            suffix =  (suffix ? suffix : 1) * nums[n - 1 - i];
	        
	        maxAns = max(maxAns, max(prefix, suffix));
	        
	    }
	    
	    return maxAns;
        
    }
};