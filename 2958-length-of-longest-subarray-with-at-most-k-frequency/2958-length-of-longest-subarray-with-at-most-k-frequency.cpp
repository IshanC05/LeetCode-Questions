class Solution {
public:    
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size(), maxF = 0;
        
        int i = 0, j = 0, res = 0;
        
        unordered_map<int,int>freq;
        
        while(j < n){
            
            ++freq[nums[j]];
            
            maxF = max(maxF, freq[nums[j]]);
            
            while(i < j && maxF > k){
                
                if(maxF == freq[nums[i]])   --maxF;
                
                --freq[nums[i]];
                
                ++i;
                
            }
            
            res = max(res, j - i + 1);
            
            ++j;
            
        }
        
        return res;
        
    }
};