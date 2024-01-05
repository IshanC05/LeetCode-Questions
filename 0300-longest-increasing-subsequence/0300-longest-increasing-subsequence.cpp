class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp = {nums[0]};
        
        for(int i = 1; i < nums.size(); i++){            
            bool used = false;
            
            for(int j = 0; j < temp.size(); j++){
                if(temp[j] >= nums[i]){
                    temp[j] = nums[i];
                    used = true;
                    break;
                }    
            }
            
            if(!used)   temp.push_back(nums[i]);
        }
        
        return temp.size();
    }
};