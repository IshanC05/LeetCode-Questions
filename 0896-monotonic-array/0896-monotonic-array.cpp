class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool ans1 = true, ans2 = true;
        
        for(int i = 0; i < nums.size() - 1; i++){
            
            if(nums[i] > nums[i + 1])   ans1 = false;
            
        }
        
        for(int i = 0; i < nums.size() - 1; i++){
            
            if(nums[i] < nums[i + 1])   ans2 = false;
            
        }
        
        return (ans1 || ans2);
        
    }
};