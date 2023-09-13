class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int n = nums.size();
        int rightSum = 0;
               
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