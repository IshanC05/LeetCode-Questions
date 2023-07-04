class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int mask = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            
            mask = (mask ^ nums[i]);
            
        }
        
        return mask;
    }
};