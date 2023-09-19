class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            
            int idx = abs(nums[i]);
            
            int elemAtIdx = nums[idx];
            
            if(elemAtIdx < 0)   return idx;
            
            nums[idx] = -nums[idx];
        }
        
        return -1;
        
    }
};