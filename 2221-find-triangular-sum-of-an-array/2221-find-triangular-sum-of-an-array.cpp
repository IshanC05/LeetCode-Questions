class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        vector<int>temp;
        
        while(nums.size() != 1){
            
            for(int i = 0; i < nums.size() - 1; i++){
                
                int sum = (nums[i] + nums[i + 1]) % 10;
                
                temp.push_back(sum);
                
            }
            
            nums = temp;
            
            temp.clear();
            
        }
        
        return nums[0];
        
    }
};