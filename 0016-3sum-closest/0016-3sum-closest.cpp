class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), closest = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < n - 2; i++){
            
            int l = i + 1, r = n - 1;
            
            while(l < r){
                
                int currSum = nums[i] + nums[l] + nums[r];
                
                if(target == currSum)   return currSum;
                
                else if(abs(target - closest) > abs(target - currSum))  closest = currSum;
                
                if(currSum > target)    --r;
                
                else    ++l;
                
            }
            
        }
        
        return closest;
        
    }
};