class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int count = 0, i = n - 2, j;
        
        while(i >= 0){
            
            while(i >= 0 && nums[i] == nums[i + 1]) 
                --i;
            
            if(i < 0)   
                break;
            
            j = i + 1;
            
            nums[j] = nums[i];
            
            count += n - j;
            
        }
        
        return count;
        
    }
};