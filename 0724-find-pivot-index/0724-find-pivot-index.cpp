class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int rightSum = 0, n = nums.size();
        
        for(int i : nums){
            rightSum += i;
        }   
        
        int leftSum = 0;
        
        for(int i = 0; i < n; i++){
            
            rightSum -= nums[i];
            
            if(leftSum == rightSum)     return i;
            
            leftSum += nums[i];           
            
        }
        
        return -1;
    }
};