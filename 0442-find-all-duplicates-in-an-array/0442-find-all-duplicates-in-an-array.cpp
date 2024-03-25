class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;
        
        for(int i : nums){
            int idx = abs(i) - 1;
            
            if(nums[idx] < 0)   
                res.push_back(idx + 1);
            
            nums[idx] = -nums[idx];
        }
        
        return res;
    }
};